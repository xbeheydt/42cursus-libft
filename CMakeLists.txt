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
	"include/get_next_line.h"
	"include/ft_printf.h"
) 
set(
	SOURCE_FILES
	"src/ft_atoi.c"
	"src/ft_bzero.c"
	"src/ft_calloc.c"
	"src/ft_isalnum.c"
	"src/ft_isalpha.c"
	"src/ft_isascii.c"
	"src/ft_isdigit.c"
	"src/ft_islower.c"
	"src/ft_isprint.c"
	"src/ft_isspace.c"
	"src/ft_isupper.c"
	"src/ft_itoa.c"
	"src/ft_lstadd_back.c"
	"src/ft_lstadd_front.c"
	"src/ft_lstclear.c"
	"src/ft_lstdelone.c"
	"src/ft_lstiter.c"
	"src/ft_lstlast.c"
	"src/ft_lstmap.c"
	"src/ft_lstnew.c"
	"src/ft_lstsize.c"
	"src/ft_memchr.c"
	"src/ft_memcmp.c"
	"src/ft_memcpy.c"
	"src/ft_memmove.c"
	"src/ft_memset.c"
	"src/ft_putchar_fd.c"
	"src/ft_putendl_fd.c"
	"src/ft_putnbr_fd.c"
	"src/ft_putstr_fd.c"
	"src/ft_split.c"
	"src/ft_strchr.c"
	"src/ft_strdup.c"
	"src/ft_striteri.c"
	"src/ft_strjoin.c"
	"src/ft_strlcat.c"
	"src/ft_strlcpy.c"
	"src/ft_strlen.c"
	"src/ft_strmapi.c"
	"src/ft_strncmp.c"
	"src/ft_strnstr.c"
	"src/ft_strrchr.c"
	"src/ft_strtrim.c"
	"src/ft_substr.c"
	"src/ft_tolower.c"
	"src/ft_toupper.c"
	"src/ft_isspace.c"
	"src/ft_putunbr_fd.c"
	"src/ft_puthnbr.c"
	"src/get_next_line/get_next_line.c"
	"src/get_next_line/get_next_line_utils.c"
	"src/ft_printf/core.c"
	"src/ft_printf/hexadecimal.c"
	"src/ft_printf/integer.c"
	"src/ft_printf/parser.c"
	"src/ft_printf/string.c"
	"src/ft_printf/utils.c"
)
set(
	HEADER_FILE_TESTS
	"tests/.tests.h"
) 
set(
	SOURCE_FILE_TESTS
	"tests/.tests.c"
	"tests/.test_main.c"
	"tests/.test_ft_atoi.c"
	"tests/.test_ft_bzero.c"
	"tests/.test_ft_calloc.c"
	"tests/.test_ft_isalnum.c"
	"tests/.test_ft_isalpha.c"
	"tests/.test_ft_isascii.c"
	"tests/.test_ft_isdigit.c"
	"tests/.test_ft_islower.c"
	"tests/.test_ft_isprint.c"
	"tests/.test_ft_isspace.c"
	"tests/.test_ft_isupper.c"
	"tests/.test_ft_itoa.c"
	"tests/.test_ft_lstadd_back.c"
	"tests/.test_ft_lstadd_front.c"
	"tests/.test_ft_lstclear.c"
	"tests/.test_ft_lstdelone.c"
	"tests/.test_ft_lstiter.c"
	"tests/.test_ft_lstlast.c"
	"tests/.test_ft_lstmap.c"
	"tests/.test_ft_lstnew.c"
	"tests/.test_ft_lstsize.c"
	"tests/.test_ft_memchr.c"
	"tests/.test_ft_memcmp.c"
	"tests/.test_ft_memcpy.c"
	"tests/.test_ft_memmove.c"
	"tests/.test_ft_memset.c"
	"tests/.test_ft_putchar_fd.c"
	"tests/.test_ft_putendl_fd.c"
	"tests/.test_ft_puthnbr_fd.c"
	"tests/.test_ft_putnbr.c"
	"tests/.test_ft_putstr_fd.c"
	"tests/.test_ft_putunbr_fd.c"
	"tests/.test_ft_split.c"
	"tests/.test_ft_strchr.c"
	"tests/.test_ft_strdup.c"
	"tests/.test_ft_striteri.c"
	"tests/.test_ft_strjoin.c"
	"tests/.test_ft_strlcat.c"
	"tests/.test_ft_strlcpy.c"
	"tests/.test_ft_strlen.c"
	"tests/.test_ft_strmapi.c"
	"tests/.test_ft_strncmp.c"
	"tests/.test_ft_strnstr.c"
	"tests/.test_ft_strrchr.c"
	"tests/.test_ft_strtrim.c"
	"tests/.test_ft_substr.c"
	"tests/.test_ft_tolower.c"
	"tests/.test_ft_toupper.c"
	"tests/get_next_line/.test_gnl_get_buffer.c"
	"tests/get_next_line/.test_gnl_clear_buffer.c"
	"tests/get_next_line/.test_gnl_get_line.c"
	"tests/get_next_line/.test_gnlt_line_realloc.c"
	"tests/get_next_line/.test_gnl_get_next_line.c"
	"tests/ft_printf/.test_ft_printf.c"
)

if($ENV{INTERNAL})
	message("INTERNAL defined")
	add_compile_definitions(INTERNAL=1)
endif()
if($ENV{MANDATORY})
	message("MANDATORY defined")
	add_compile_definitions(MANDATORY)
endif()
if($ENV{BONUS})
	message("BONUS defined")
	add_compile_definitions(BONUS=$ENV{BONUS})
endif()
if($ENV{BUFFER_SIZE})
	message("BUFFER_SIZE defined")
	add_compile_definitions(BUFFER_SIZE=$ENV{BUFFER_SIZE})
endif()

# Create static lib target
add_library(libft STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(
	libft
	PUBLIC
	"include"
)

# Create tests executable target
add_executable(tests ${HEADER_FILE_TESTS} ${SOURCE_FILE_TESTS})
target_link_libraries(tests PRIVATE libft)
target_include_directories(
	tests
	PRIVATE
	"include"
	"src/ft_printf"
	"tests"
)

# IDE tree view
source_group(
	"Header_Files"
	FILES ${HEADER_FILES} ${HEADER_FILE_TESTS}
)

source_group(
	"Source_Files"
	FILES ${SOURCE_FILES} ${SOURCE_FILE_TESTS}
)