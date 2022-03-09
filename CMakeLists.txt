# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (
	"42cursus-libft"
	VERSION 0.1.0
)

set(
	HEADER_FILES
	"include/libft.h"
) 
set(
	SOURCE_FILES
)
set(
	HEADER_FILE_TESTS
	".tests.h"
) 
set(
	SOURCE_FILE_TESTS
	".test_main.c"
)

# Include libft project as library
# set the output destination
set(
	LIBFT_LIB
	"build/lib/libft.a"
)
# and will run each time you type make
add_custom_target(
	build_libft ALL
	COMMAND ${CMAKE_MAKE_PROGRAM} all
	WORKING_DIRECTORY "."
	COMMENT "Original libft Makefile target"
	)

# Create a lib for tests
add_library(libft_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})
# Import target "push_swap" for configuration ""
set_property(TARGET libft APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION_NOCONFIG "${LIBFT_LIB}")

# now you can use push_swap as if it were a regular cmake built target in your project
add_dependencies(libft build_libft)

# Include sub-projects

# IDE tree view
source_group(
	"Header_Files"
	FILES ${HEADER_FILES}
)

source_group(
	"Source_Files"
	FILES ${SOURCE_FILES}
)

source_group(
	"Header_File_Tests"
	FILES ${HEADER_FILE_TESTS}
)

source_group(
	"Source_File_Tests"
	FILES ${SOURCE_FILE_TESTS}
)