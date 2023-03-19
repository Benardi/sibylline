# If pkg-config is not installed on the system, then the CHECK_INSTALL_DIR var
# must be set to the install location of Check. For example, on Windows, this
# may be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")



if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  # Only check for testing dependencies if in Debug mode 
  find_package(Check REQUIRED)
  find_package(Valgrind REQUIRED)
  include(CheckCSourceCompiles)
  include(CheckCSourceRuns)
  include(CheckFunctionExists)
  include(CheckIncludeFile)
  include(CheckIncludeFiles)
  include(CheckLibraryExists)
  include(CheckSymbolExists)
  include(CheckTypeSize)
  
  if(NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Release" AND NOT "${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    file(GLOB test_src ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
    
    foreach(test_src_file ${test_src})
    
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" test_name ${test_src_file})
        string(REPLACE ".c" "" test_name ${test_name})
        set(valgrind_test "valgrind_${test_name}") 
    
        # Since Check uses Threads to paralelize the tests, it's mandatory
        # add pthread as a dependency, alongside the Check libraries.
        add_executable(${test_name} ${test_src_file})
        target_link_libraries(${test_name} sibylline ${CHECK_LIBRARIES} pthread m)
    
        # Create testing target and redirect its output to `Testing` folder
        add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)
        set_tests_properties(${test_name} PROPERTIES TIMEOUT 30) 
    
    endforeach(test_src_file ${test_src})
    
    foreach(test_src_file ${test_src})
    
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" test_name ${test_src_file})
        string(REPLACE ".c" "" test_name ${test_name})
        set(valgrind_test "valgrind_${test_name}") 
    
        # Aditional Valgrind test to check memory leaks in code
        add_test(NAME ${valgrind_test}
                 COMMAND ${VALGRIND_PROGRAM} --leak-check=full
                 --error-exitcode=1 $<TARGET_FILE:${test_name}>)
    
    endforeach(test_src_file ${test_src})
  endif()
endif()
