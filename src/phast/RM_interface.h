/*! @file IPhreeqc.h
	@brief C/Fortran Documentation
*/
#ifndef RM_INTERFACE_H
#define RM_INTERFACE_H
#include "IPhreeqc.h"
#include "Var.h"
#if defined(_MSC_VER)
#define FC_FUNC_(name,NAME) NAME
#endif

#if defined(FC_FUNC_)
// Called from Fortran or C++
#define RM_calculate_well_ph               FC_FUNC_ (rm_calculate_well_ph,             RM_CALCULATE_WELL_PH)
#define RM_close_files                     FC_FUNC_ (rm_close_files,                   RM_CLOSE_FILES)    
#define RM_convert_to_molal                FC_FUNC_ (rm_convert_to_molal,              RM_CONVERT_TO_MOLAL)   
#define RM_Create                          FC_FUNC_ (rm_create,                        RM_CREATE)
#define RM_CreateMapping                   FC_FUNC_ (rm_createmapping,                 RM_CREATEMAPPING)
#define RM_Destroy                         FC_FUNC_ (rm_destroy,                       RM_DESTROY)
#define RM_distribute_initial_conditions   FC_FUNC_ (rm_distribute_initial_conditions, RM_DISTRIBUTE_INITIAL_CONDITIONS)
#define RM_distribute_initial_conditions_mix  FC_FUNC_ (rm_distribute_initial_conditions_mix, RM_DISTRIBUTE_INITIAL_CONDITIONS_MIX)
#define RM_Error                           FC_FUNC_ (rm_error,                         RM_ERROR)
#define RM_ErrorMessage                    FC_FUNC_ (rm_errormessage,                  RM_ERRORMESSAGE)
#define RM_FindComponents                  FC_FUNC_ (rm_findcomponents,                RM_FINDCOMPONENTS)
#define RM_GetChemistryCellCount           FC_FUNC_ (rm_getchemistrycellcount,         RM_GETNCHEMISTRYCELLCOUNT)
#define RM_GetComponent                    FC_FUNC_ (rm_getcomponent,                  RM_GETCOMPONENT)
#define RM_GetFilePrefix                   FC_FUNC_ (rm_getfileprefix,                 RM_GETFILEPREFIX)
#define RM_GetMpiMyself                    FC_FUNC_ (rm_getmpimyself,                  RM_GETMPIMYSELF)
#define RM_GetGridCellCount                FC_FUNC_ (rm_getgridcellcount,              RM_GETGRIDCELLCOUNT)
#define RM_GetNthSelectedOutputUserNumber  FC_FUNC_ (rm_getnthselectedoutputusernumber, RM_GETNTHSELECTEDOUTPUTUSERNUMBER)
#define RM_GetSelectedOutput               FC_FUNC_ (rm_getselectedoutput,             RM_GETSELECTEDOUTPUT)
#define RM_GetSelectedOutputColumnCount    FC_FUNC_ (rm_getselectedoutputcolumncount,  RM_GETSELECTEDOUTPUTCOLUMNCOUNT)
#define RM_GetSelectedOutputCount          FC_FUNC_ (rm_getselectedoutputcount,        RM_GETSELECTEDOUTPUTCOUNT)
#define RM_GetSelectedOutputHeading        FC_FUNC_ (rm_getselectedoutputheading,      RM_GETSELECTEDOUTPUTHEADING)
#define RM_GetSelectedOutputRowCount       FC_FUNC_ (rm_getselectedoutputrowcount,     RM_GETSELECTEDOUTPUTROWCOUNT)
#define RM_GetTime                         FC_FUNC_ (rm_gettime,                       RM_GETTIME)
#define RM_GetTimeConversion               FC_FUNC_ (rm_gettimeconversion,             RM_GETTIMECONVERSION)
#define RM_GetTimeStep                     FC_FUNC_ (rm_gettimestep,                   RM_GETTIMESTEP)
#define RM_InitialPhreeqcRun               FC_FUNC_ (rm_initialphreeqcrun,             RM_INITIALPHREEQCRUN)
#define RM_LoadDatabase                    FC_FUNC_ (rm_loaddatabase,                  RM_LOADDATABASE)
#define RM_LogMessage                      FC_FUNC_ (rm_logmessage,                    RM_LOGMESSAGE)
#define RM_LogScreenMessage                FC_FUNC_ (rm_logscreenmessage,              RM_LOGSCREENMESSAGE)
#define RM_OpenFiles                       FC_FUNC_ (rm_openfiles,                     RM_OPENFILES)
#define RM_RunCells                        FC_FUNC_ (rm_runcells,                      RM_RUNCELLS)
#define RM_ScreenMessage                   FC_FUNC_ (rm_screenmessage,                 RM_SCREENMESSAGE)
#define RM_send_restart_name               FC_FUNC_ (rm_send_restart_name,             RM_SEND_RESTART_NAME)
#define RM_SetCurrentSelectedOutputUserNumber  FC_FUNC_ (rm_setcurrentselectedoutputusernumber, RM_SETCURRENTSELECTEDOUTPUTUSERNUMBER)
#define RM_setup_boundary_conditions       FC_FUNC_ (rm_setup_boundary_conditions,     RM_SETUP_BOUNDARY_CONDITIONS)
#define RM_SetDensity                      FC_FUNC_ (rm_setdensity,                    RM_SETDENSITY)
#define RM_SetFilePrefix                   FC_FUNC_ (rm_setfileprefix,                 RM_SETFILEPREFIX)
#define RM_set_free_surface                FC_FUNC_ (rm_set_free_surface,              RM_SET_FREE_SURFACE)
#define RM_SetInputUnits                   FC_FUNC_ (rm_setinputunits,                 RM_SETINPUTUNITS)
#define RM_set_nodes                       FC_FUNC_ (rm_set_nodes,                     RM_SET_NODES)
#define RM_set_printing                    FC_FUNC_ (rm_set_printing,                  RM_SET_PRINTING)
#define RM_set_print_chem_mask             FC_FUNC_ (rm_set_print_chem_mask,           RM_SET_PRINT_CHEM_MASK)
#define RM_SetPressure                     FC_FUNC_ (rm_setpressure,                   RM_SETPRESSURE)
#define RM_SetPv0                          FC_FUNC_ (rm_setpv0,                        RM_SETPV0)
#define RM_SetPv                           FC_FUNC_ (rm_setpv,                         RM_SETPV)
#define RM_SetRebalance                    FC_FUNC_ (rm_setrebalance,                  RM_SETREBALANCE)
#define RM_SetSaturation                   FC_FUNC_ (rm_setsaturation,                 RM_SETSATURATION)
#define RM_set_steady_flow                 FC_FUNC_ (rm_set_steady_flow,               RM_SET_STEADY_FLOW)
#define RM_SetTemperature                  FC_FUNC_ (rm_settemperature,                RM_SETTEMPERATURE)
#define RM_SetTimeConversion               FC_FUNC_ (rm_settimeconversion,             RM_SETTIMECONVERSION)
#define RM_SetVolume					   FC_FUNC_ (rm_setvolume,                     RM_SETVOLUME)
#define RM_Module2Concentrations           FC_FUNC_ (rm_module2concentrations,         RM_MODULE2CONCENTRATIONS)
#define RM_write_bc_raw                    FC_FUNC_ (rm_write_bc_raw,                  RM_WRITE_BC_RAW)
#define RM_write_output                    FC_FUNC_ (rm_write_output,                  RM_WRITE_OUTPUT)
#define RM_write_restart				   FC_FUNC_ (rm_write_restart,                 RM_WRITE_RESTART)
#define RM_WarningMessage                  FC_FUNC_ (rm_warningmessage,                RM_WARNINGMESSAGE)
#endif
#ifdef SKIP
#define RM_calculate_well_ph                  rm_calculate_well_ph
#define RM_close_files                        rm_close_files
#define RM_convert_to_molal                   rm_convert_to_molal
#define RM_Create                             RM_Create
#define RM_Destroy                            rm_destroy
#define RM_distribute_initial_conditions      rm_distribute_initial_conditions
#define RM_Error                              rm_error
#define RM_FindComponents                    RM_FindComponents
//#define RM_fractions2solutions                rm_fractions2solutions
#define RM_GetComponent                      RM_GetComponent
#define RM_InitialPhreeqcRun                RM_InitialPhreeqcRun
#define RM_LoadDatabase                      RM_LoadDatabase
#define RM_LogScreenMessage                     RM_LogScreenMessage
#define RM_OpenFiles                         RM_OpenFiles
#define RM_RunCells                          RM_RunCells
#define RM_send_restart_name                  rm_send_restart_name
#define RM_setup_boundary_conditions          rm_setup_boundary_conditions
#define RM_SetDensity	                      RM_SetDensity
#define RM_SetInputUnits                    RM_SetInputUnits
#define RM_CreateMapping                        RM_CreateMapping
#define RM_set_nodes                          rm_set_nodes
#define RM_set_printing                       rm_set_printing
#define RM_set_print_chem_mask                rm_set_print_chem_mask
#define RM_set_pressure                       rm_set_pressure
#define RM_SetPv0                             rm_setpv0
#define RM_SetPv                              rm_setpv
#define RM_SetRebalance                      RM_SetRebalance
#define RM_SetSaturation                      rm_setsaturation
#define RM_SetTemperature	                      RM_SetTemperature
#define RM_SetTimeConversion				  rm_settimeconversion
#define RM_SetVolume                          rm_setvolume
#define RM_Module2Concentrations              rm_module2concentrations
#define RM_write_bc_raw                       rm_write_bc_raw
#define RM_write_output                       rm_write_output
#define RM_write_restart					  rm_write_restart
#endif

class RM_interface
{
public:
	static int CreateReactionModule(int *nxyz, int *nthreads);
	static IRM_RESULT DestroyReactionModule(int *n);
	static Reaction_module* GetInstance(int n);
	static void CleanupReactionModuleInstances(void);
	static PHRQ_io phast_io;

private:
	friend class Reaction_module;
	static std::map<size_t, Reaction_module*> Instances;
	static size_t InstancesIndex;
};

#if defined(__cplusplus)
extern "C" {
#endif
void RM_calculate_well_ph(int *id, double *c, double * ph, double * alkalinity);
void RM_close_files(int * solute);
void RM_convert_to_molal(int *id, double *c, int *n, int *dim);
int  RM_Create(int *nxyz, int *nthreads);
IRM_RESULT RM_CreateMapping (int *id, int *grid2chem=NULL); 
IRM_RESULT  RM_Destroy(int *id);
IRM_RESULT RM_distribute_initial_conditions(int *id,
		int *initial_conditions1);		// 7 x nxyz end-member 1
IRM_RESULT RM_distribute_initial_conditions_mix(int *id,
		int *initial_conditions1,		// 7 x nxyz end-member 1
		int *initial_conditions2,		// 7 x nxyz end-member 2
		double *fraction1			    // 7 x nxyz fraction of end-member 1
		);
void RM_Error(int *id);
void RM_ErrorMessage(const char *err_str, long l = -1);
int RM_FindComponents(int *id);
IRM_RESULT RM_GetComponent(int * id, int * num, char *chem_name, int l1 = -1);
IRM_RESULT RM_GetFilePrefix(int *id, char *prefix, long l = -1);
int RM_GetMpiMyself(int *id);
int RM_GetChemistryCellCount(int *id);
int RM_GetGridCellCount(int *id);
int RM_GetNthSelectedOutputUserNumber(int *id, int *i);
IRM_RESULT RM_GetSelectedOutput(int *id, double *so = NULL);
int RM_GetSelectedOutputColumnCount(int *id);
int RM_GetSelectedOutputCount(int *id);
IRM_RESULT RM_GetSelectedOutputHeading(int *id, int * icol, char * heading, int length);
int RM_GetSelectedOutputRowCount(int *id);
double RM_GetTime(int *id);
double RM_GetTimeConversion(int *id);
double RM_GetTimeStep(int *id);
IRM_RESULT RM_InitialPhreeqcRun(int * id, char *db_name, char *chem_name, char *prefix_name, int l1, int l2, int l3);
void RM_LogMessage(const char *err_str, long l = -1);
void RM_LogScreenMessage(char *err_str, long l = -1);
void RM_OpenFiles(int * solute, char * prefix, int l_prefix);
void RM_open_error_file(void);
void RM_open_output_file(char * prefix, int l_prefix);
void RM_open_punch_file(char * prefix, int l_prefix);
void RM_open_log_file(char * prefix, int l_prefix);
void RM_Module2Concentrations(int *id, double *c = NULL);
void RM_RunCells(int *id,
			 double *time,					        // time from transport 
			 double *time_step,				        // time step from transport
 			 double *concentration,					// mass fractions nxyz:components
			 int * stop_msg);
void RM_ScreenMessage(const char *err_str, long l = -1);
void RM_send_restart_name(int *id, char * s, long l);
int  RM_SetCurrentSelectedOutputUserNumber(int *id, int *i);
void RM_setup_boundary_conditions(
			int *id,
			int *n_boundary, 
			int *boundary_solution1,  
			int *boundary_solution2, 
			double *fraction1,
			double *boundary_c, 
			int *dim);
void RM_SetDensity(int *id, double *t);
IRM_RESULT RM_SetFilePrefix(int *id, const char *prefix, long l = -1);
void RM_set_free_surface(int *id, int *t);
void RM_SetInputUnits (int *id, int *sol=NULL, int *pp=NULL, int *ex=NULL, 
						 int *surf=NULL, int *gas=NULL, int *ss=NULL, int *kin=NULL);
void RM_set_nodes(int *id, double *x_node, double *y_node, double *z_node);
void RM_set_printing(int *id, int *print_chem, int *print_hdf, int *print_restart);
void RM_set_print_chem_mask(int *id, int *t);
void RM_SetPressure(int *id, double *t);
void RM_SetPv(int *id, double *t);
void RM_SetPv0(int *id, double *t);
void RM_SetRebalance(int *id, int *method, double *f);
void RM_SetSaturation(int *id, double *t);
void RM_set_steady_flow(int *id, int *t);
void RM_SetTemperature(int *id, double *t);
void RM_SetTimeConversion(int *id, double *t);
void RM_SetVolume(int *id, double *t);
void RM_WarningMessage(const char *err_str, long l = -1);
void RM_write_bc_raw(int *id, 
			int *solution_list, 
			int * bc_solution_count, 
			int * solution_number, 
			char *prefix, 
			int prefix_l);
void RM_write_output(int *id);
void RM_write_restart(int *id);

#if defined(__cplusplus)
}
#endif

// Global functions
//inline std::string trim_right(const std::string &source , const std::string& t = " \t")
//{
//	std::string str = source;
//	return str.erase( str.find_last_not_of(t) + 1);
//}
//
//inline std::string trim_left( const std::string& source, const std::string& t = " \t")
//{
//	std::string str = source;
//	return str.erase(0 , source.find_first_not_of(t) );
//}
//
//inline std::string trim(const std::string& source, const std::string& t = " \t")
//{
//	std::string str = source;
//	return trim_left( trim_right( str , t) , t );
//} 
#endif // RM_INTERFACE_H
