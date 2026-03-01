# tests/CMakeLists.txt

include(CTest)

# Optional: allow forcing Valgrind on/off explicitly
option(ENABLE_VALGRIND "Enable Valgrind tests (requires Valgrind installed)" OFF)

# Enable tests in:
# - Debug single-config
# - any config in multi-config generators (Xcode, Ninja Multi-Config)
set(ENABLE_TESTS OFF)
if(CMAKE_CONFIGURATION_TYPES)
  set(ENABLE_TESTS ON)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(ENABLE_TESTS ON)
endif()

if(ENABLE_TESTS)

  message(STATUS "Configuring unit tests")

  # Only check for testing dependencies if in Debug mode (single-config),
  # or always for multi-config generators (gated by ENABLE_TESTS above).
  find_package(Check REQUIRED)
  find_package(Threads REQUIRED)

  # Valgrind is now truly optional with the updated FindValgrind.cmake
  # - If ENABLE_VALGRIND=ON, require it.
  # - Otherwise, try quietly and only add valgrind tests if found.
  if(ENABLE_VALGRIND)
    find_package(Valgrind REQUIRED)
  else()
    find_package(Valgrind QUIET)
  endif()

  include(CheckCSourceCompiles)
  include(CheckCSourceRuns)
  include(CheckFunctionExists)
  include(CheckIncludeFile)
  include(CheckIncludeFiles)
  include(CheckLibraryExists)
  include(CheckSymbolExists)
  include(CheckTypeSize)

  file(GLOB test_src "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

  foreach(test_src_file ${test_src})

    get_filename_component(test_name "${test_src_file}" NAME_WE)
    set(valgrind_test "valgrind_${test_name}")

    add_executable(${test_name} ${test_src_file})

    # Link Check + threads portably
    if(TARGET Check::Check)
      target_link_libraries(${test_name}
        PRIVATE
          sibylline
          Check::Check
          Threads::Threads
          m
      )
    else()
      target_link_libraries(${test_name}
        PRIVATE
          sibylline
          ${CHECK_LIBRARIES}
          Threads::Threads
          m
      )
    endif()

    # Create testing target and redirect its output to `Testing` folder
    add_test(
      NAME ${test_name}
      COMMAND ${test_name}
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing
    )
    set_tests_properties(${test_name} PROPERTIES TIMEOUT 30)

    # Additional Valgrind test to check memory leaks in code (only if found)
    if(Valgrind_FOUND)
      add_test(
        NAME ${valgrind_test}
        COMMAND ${Valgrind_PROGRAM}
                --leak-check=full
                --error-exitcode=1
                $<TARGET_FILE:${test_name}>
      )
    endif()

  endforeach()

endif()