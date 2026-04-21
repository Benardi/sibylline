# https://libcheck.github.io/check/
cmake_minimum_required(VERSION 4.0)

project(sibylline)

# Custom cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set release as default build type
if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Configure wether libraries will be static or shared linked
set(BUILD_SHARED_LIBS ON)

set(SIBYLLINE_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SIBYLLINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Show all warning messages
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -std=c99 -pedantic \
                   -Wmissing-prototypes -Wstrict-prototypes \
                   -Wold-style-definition")

option(ENABLE_ASAN "Enable AddressSanitizer (detects memory errors)" OFF)
if(ENABLE_ASAN)
  add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
  add_link_options(-fsanitize=address)
endif()

# ASan + UBSan: closest cross-platform equivalent to Valgrind.
# Adds leak detection on Linux (LSan); on macOS detects everything except leaks.
option(ENABLE_SANITIZERS "Enable AddressSanitizer + UndefinedBehaviorSanitizer" OFF)
if(ENABLE_SANITIZERS)
  set(_sanitizers "address,undefined")
  if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    string(APPEND _sanitizers ",leak")
  endif()
  add_compile_options(-fsanitize=${_sanitizers} -fno-omit-frame-pointer)
  add_link_options(-fsanitize=${_sanitizers})
endif()

file(GLOB src ${SIBYLLINE_SRC_ROOT}/*.c)

include_directories(${SIBYLLINE_INCLUDE_DIR})

# Generate the shared library from sources
add_library(sibylline ${src})

# install shared library at /usr/lib. Use "sudo make install" to apply 
install(TARGETS sibylline DESTINATION lib)

enable_testing()
add_subdirectory(tests)
