# https://libcheck.github.io/check/
cmake_minimum_required(VERSION 3.1)

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
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -std=c89 -pedantic \
                   -Wmissing-prototypes -Wstrict-prototypes \
                   -Wold-style-definition")


file(GLOB src ${SIBYLLINE_SRC_ROOT}/*.c)

include_directories(${SIBYLLINE_INCLUDE_DIR})

# Generate the shared library from sources
add_library(sibylline ${src})

# install shared library at /usr/lib. Use "sudo make install" to apply 
install(TARGETS sibylline DESTINATION lib)

enable_testing()
add_subdirectory(tests)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
