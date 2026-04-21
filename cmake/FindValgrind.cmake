# FindValgrind.cmake
#
# This module defines:
#   Valgrind_FOUND
#   Valgrind_INCLUDE_DIR
#   Valgrind_PROGRAM
#
# Backward compatible:
#   VALGRIND_FOUND
#   VALGRIND_INCLUDE_DIR
#   VALGRIND_PROGRAM
#
# If you have valgrind installed in a non-standard place, you can define:
#   VALGRIND_PREFIX

# Be quiet unless explicitly asked
if(NOT Valgrind_FIND_QUIETLY)
  message(STATUS "Valgrind Prefix: ${VALGRIND_PREFIX}")
endif()

# Prefix hints (macOS Homebrew + common Unix locations)
set(_VALGRIND_PREFIX_HINTS
  ${VALGRIND_PREFIX}
  /opt/homebrew
  /usr/local
  /usr
  /opt/local
)

# Include dir (often absent on macOS; keep it optional unless you truly need headers)
find_path(Valgrind_INCLUDE_DIR
  NAMES valgrind/memcheck.h
  HINTS ${_VALGRIND_PREFIX_HINTS}
  PATH_SUFFIXES include
)

# Program (this is the main thing most projects need)
find_program(Valgrind_PROGRAM
  NAMES valgrind
  HINTS ${_VALGRIND_PREFIX_HINTS}
  PATH_SUFFIXES bin
)

include(FindPackageHandleStandardArgs)

# If you require headers, add Valgrind_INCLUDE_DIR here too.
# For running valgrind, Valgrind_PROGRAM is enough.
find_package_handle_standard_args(Valgrind
  REQUIRED_VARS Valgrind_PROGRAM
)

# Backward compatible variable names
set(VALGRIND_INCLUDE_DIR "${Valgrind_INCLUDE_DIR}")
set(VALGRIND_PROGRAM     "${Valgrind_PROGRAM}")
set(VALGRIND_FOUND       "${Valgrind_FOUND}")

mark_as_advanced(Valgrind_INCLUDE_DIR Valgrind_PROGRAM)
mark_as_advanced(VALGRIND_INCLUDE_DIR VALGRIND_PROGRAM)