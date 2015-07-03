set(CTEST_BUILD_NAME "VS2012-mpi-x64")
set(CTEST_SITE "IGSKAHHWWSCHARL")

set(CTEST_SOURCE_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}")
set(CTEST_BINARY_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}/_build_mpi_x64")
set(CTEST_CMAKE_GENERATOR "Visual Studio 11 2012 Win64")

set(BUILD_OPTIONS -DCMAKE_INSTALL_PREFIX:PATH=${CTEST_BINARY_DIRECTORY}/INSTALL
                  -DHDF5_DIR:PATH=C:/Program\ Files/HDF_Group/HDF5/1.8.14/cmake/hdf5
                  -DPHAST_BUILD_MPI:BOOL=ON
                  -DPHAST_BUILD_OPENMP:BOOL=OFF)
                  
CTEST_START("Experimental")
#ctest_update([SOURCE source] [RETURN_VALUE res])
CTEST_CONFIGURE(BUILD "${CTEST_BINARY_DIRECTORY}"
                OPTIONS "${BUILD_OPTIONS}")
CTEST_BUILD(BUILD "${CTEST_BINARY_DIRECTORY}")
#CTEST_TEST(BUILD "${CTEST_BINARY_DIRECTORY}")
CTEST_BUILD(BUILD "${CTEST_BINARY_DIRECTORY}" TARGET INSTALL)
#CTEST_BUILD(BUILD "${CTEST_BINARY_DIRECTORY}" TARGET PACKAGE)
###CTEST_SUBMIT()