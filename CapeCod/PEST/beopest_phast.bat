@echo off
SETLOCAL

REM Sychronize latest WEBMOD executable, create the tsproc and PEST command files, and start beopest as master
REM Help printed if command entered with no arguments
IF %1.==. GOTO :USAGE
if %2.==. GOTO :USAGE


REM Set variables
set PHAST_ROOT_NAME=full3d
set NODES=%1
set PHAST_NODES=%2
REM ":\=/" replaces \ with /
set PST=phast.pst
set HOME=%cd%
set HOME_SED=%HOME:\=/%
set "INPUT_DIR=%HOME%\Input"
set INPUT_DIR_SED=%INPUT_DIR:\=/%
set "PEST_FILES_DIR=%HOME%\Pest_files"
set PEST_FILES_DIR_SED=%PEST_FILES_DIR:\=/%
set "PROJECT_DIR=%HOME%\pest_run_dir"
set PROJECT_DIR_SED=%PROJECT_DIR:\=/%
set "PEST_BIN_DIR=%HOME%\bin"
set PEST_BIN_DIR_SED=%PEST_BIN_DIR:\=/%
set OBSERVATIONS_DIR=%HOME%\Data

REM check files
set errors=0
for %%i in ( 
    %INPUT_DIR%\phast.dat
    %PEST_FILES_DIR%\%PHAST_ROOT_NAME%.chem.dat.tpl
    %PEST_FILES_DIR%\%PHAST_ROOT_NAME%.trans.dat.tpl
    %PEST_FILES_DIR%\phast.pst.tpl
    %PEST_FILES_DIR%\phast.bat.tpl
    %OBSERVATIONS_DIR%\P_uM_1993.obs
    %PEST_BIN_DIR%/beopest64.exe
    %PEST_BIN_DIR%/phastinput.exe
    %PEST_BIN_DIR%/phast3-mpi.exe
    ) do (
    if NOT exist %%i (
        echo Did not find file %%i
        set errors=2
    )
)

REM quit if errors in hydro files
if %errors% == 2 (
    echo Stopping.
    goto :FINISH_UP
)
    
REM set port number
set PORT=4004 

REM setup working directory PROJECT_DIR=pest_run_dir
if exist %PROJECT_DIR% rmdir /s/q %PROJECT_DIR%
mkdir %PROJECT_DIR%

REM Sed files

REM phast.pst
call :SED @PROJECT_DIR@ %PROJECT_DIR_SED%          %PEST_FILES_DIR%\phast.pst.tpl > %PROJECT_DIR%/phast.pst1
call :SED @PHAST_ROOT_NAME@ %PHAST_ROOT_NAME%      %PROJECT_DIR%\phast.pst1       > %PROJECT_DIR%\phast.pst
DEL %PROJECT_DIR%\phast.pst1

REM phast.bat
call :SED @PEST_BIN_DIR@ %PEST_BIN_DIR_SED%      %PEST_FILES_DIR%\phast.bat.tpl > %PROJECT_DIR%\phast.bat1
call :SED @PHAST_NODES@ %PHAST_NODES%            %PROJECT_DIR%\phast.bat1       > %PROJECT_DIR%\phast.bat2
call :SED @DEL@ DEL                              %PROJECT_DIR%\phast.bat2       > %PROJECT_DIR%\phast.bat3
call :SED @PHAST_ROOT_NAME@ %PHAST_ROOT_NAME%    %PROJECT_DIR%\phast.bat3       > %PROJECT_DIR%\phast.bat
DEL %PROJECT_DIR%\phast.bat1 
DEL %PROJECT_DIR%\phast.bat2
DEL %PROJECT_DIR%\phast.bat3  

REM interpolator.control
call :SED @PHAST_ROOT_NAME@ %PHAST_ROOT_NAME%    %PEST_FILES_DIR%\interpolator.control       > %PROJECT_DIR%\interpolator.control

REM copy other files
copy %PEST_FILES_DIR%\%PHAST_ROOT_NAME%.chem.dat.tpl   %PROJECT_DIR%
copy %PEST_FILES_DIR%\%PHAST_ROOT_NAME%.trans.dat.tpl  %PROJECT_DIR%
copy %PEST_FILES_DIR%\*.ins                            %PROJECT_DIR%
copy %INPUT_DIR%\phast.dat                             %PROJECT_DIR%
copy %OBSERVATIONS_DIR%\*.obs                          %PROJECT_DIR%
REM copy %OBSERVATIONS_DIR%\*.tsv                          %PROJECT_DIR% 
	
REM make tmp dirs and run parallel pest workers
set MASTER=%COMPUTERNAME%
for /l %%X in (1, 1, %NODES%) do (
	if exist %PROJECT_DIR%\tmpest%%X rmdir /s/q %PROJECT_DIR%\tmpest%%X 
	mkdir %PROJECT_DIR%\tmpest%%X
	cd %PROJECT_DIR%\tmpest%%X
	copy %PEST_FILES_DIR%\%PHAST_ROOT_NAME%.chem.dat.tpl   .\
	copy %PEST_FILES_DIR%\%PHAST_ROOT_NAME%.trans.dat.tpl  .\
	copy %PEST_FILES_DIR%\*.ins                            .\
	copy %INPUT_DIR%\phast.dat                             .\
	copy %PROJECT_DIR%\phast.bat                           .\
	copy %PROJECT_DIR%\interpolator.control                .\
	copy %OBSERVATIONS_DIR%\*.obs                          .\
REM	copy %OBSERVATIONS_DIR%\*.tsv                          .\ 
	START /B %PEST_BIN_DIR%\beopest64.exe %PROJECT_DIR%\%PST% /H %MASTER%:%PORT% & cd %PROJECT_DIR%\..
	cd %PROJECT_DIR%\..
)

REM Run parallel pest Master
cd %PROJECT_DIR%
%PEST_BIN_DIR%\beopest64.exe %PROJECT_DIR%\%PST% /H /L /p1 :%PORT% 

REM tidy up
IF "%ERRORLEVEL%" == "0" (
    if exist %PROJECT_DIR%\..\pest_results rmdir /s/q %PROJECT_DIR%\..\pest_results
    mkdir %PROJECT_DIR%\..\pest_results
    cd %PROJECT_DIR%
REM results    
    copy %PHAST_ROOT_NAME%* 		..\pest_results
    DEL  				..\pest_results\*intermediate*
    copy interpolator.control		..\pest_results
    copy *.calc				..\pest_results
    copy *.ins				..\pest_results
    copy *.obs				..\pest_results
    copy phast*				..\pest_results
    DEL 				..\pest_results\Phast.tmp
    copy ..\beopest_phast.bat		..\pest_results
REM pest_files
    cd ..\pest_results
    mkdir pest_files
    copy ..\pest_files\*.tpl		.\pest_files
    copy ..\pest_files\*.rmf		.\pest_files
    copy ..\beopest_phast.bat		.\pest_files
REM plots
REM Plot residuals and correlation
    %PEST_BIN_DIR%\pest_plot phast.rei phast_fit.pdf none
REM Plot parameters changes
    %PEST_BIN_DIR%\parm_plot phast.pst phast.sen phast_par_calib.pdf none
REM Plot sensitivities
    %PEST_BIN_DIR%\sen_plot phast.sen phast_sensitivity.pdf
REM Plot contributions to phi by observation group
    %PEST_BIN_DIR%\pcon_plot phast.rec phast_phi.pdf none
REM Compute influence statistics
    %PEST_BIN_DIR%\infstat phast phast.infstat
    cd   %PROJECT_DIR%\..
REM
REM run sensitivity plots here
REM
) else (
    echo Beopest failed.
)

GOTO :FINISH_UP

:USAGE
echo.
echo usage: webpest_pc n_pest n_phast
echo where  n_pest is number of PEST workers to start
echo and    n_phast is number of PHAST workers for parallel PHAST
GOTO :EOF

:SED
REM -- Prepare the Command Processor --
SETLOCAL ENABLEEXTENSIONS
SETLOCAL DISABLEDELAYEDEXPANSION

::BatchSubstitude - parses a File line by line and replaces a substring"
::syntax: BatchSubstitude.bat OldStr NewStr File
::          OldStr [in] - string to be replaced
::          NewStr [in] - string to replace with
::          File   [in] - file to be parsed
:$changed 20100115
:$source http://www.dostips.com
if "%~1"=="" findstr "^::" "%~f0"&GOTO:EOF
for /f "tokens=1,* delims=]" %%A in ('"type %3|find /n /v """') do (
    set "line=%%B"
    if defined line (
        call set "line=echo.%%line:%~1=%~2%%"
        for /f "delims=" %%X in ('"echo."%%line%%""') do %%~X
    ) ELSE echo.
)
EXIT /b

:FINISH_UP
cd %PROJECT_DIR%\..