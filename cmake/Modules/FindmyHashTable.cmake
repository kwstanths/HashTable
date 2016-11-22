# - Try to find myHashTable
# Once done this will define
#  myHashTable_FOUND - System has myHashTable
#  myHashTable_INCLUDE_DIRS - The myHashTable include directories
#  myHashTable_LIBRARIES - The libraries needed to use myHashTable

find_path(myHashTable_INCLUDE_DIR
	NAMES myHashTable.hpp
	HINTS ${myHashTable_ROOT}/include
	DOC "The myHashTable include directory"
)

find_library(myHashTable_LIBRARY
	NAMES myHashTable
	HINTS ${myHashTable_ROOT}/lib
	DOC "The myHashTable library"
)

if(myHashTable_INCLUDE_DIR AND myHashTable_LIBRARY)
	set(myHashTable_FOUND 1)
endif()

# Handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE if all myHashTableed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(myHashTable DEFAULT_MSG myHashTable_INCLUDE_DIR myHashTable_LIBRARY)

if(myHashTable_FOUND)
	set(myHashTable_LIBRARIES ${myHashTable_LIBRARY} )
	set(myHashTable_INCLUDE_DIRS ${myHashTable_INCLUDE_DIR} )
endif()

# Tell cmake myHashTables to ignore the "local" variables
mark_as_advanced(myHashTable_INCLUDE_DIR myHashTable_LIBRARY)
