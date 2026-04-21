# FindCheck.cmake - Find the Check unit testing framework (libcheck)
#
# Provides:
#   Check_FOUND
#   Check_INCLUDE_DIRS
#   Check_LIBRARIES
#   Check::Check (imported target)
#
# Backward-compatible variables:
#   CHECK_FOUND
#   CHECK_INCLUDE_DIR
#   CHECK_INCLUDE_DIRS
#   CHECK_LIBRARIES

# DO NOT set cmake_minimum_required() in a Find-module.

# Prefer pkg-config when available
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
  pkg_check_modules(PC_CHECK QUIET check)
endif()

# Optional user override
set(_CHECK_HINT_INCLUDE "")
set(_CHECK_HINT_LIB "")

if(CHECK_INSTALL_DIR)
  set(_CHECK_HINT_INCLUDE "${CHECK_INSTALL_DIR}/include")
  set(_CHECK_HINT_LIB     "${CHECK_INSTALL_DIR}/lib")
endif()

# Homebrew/common prefixes fallback (Apple Silicon + Intel)
set(_CHECK_PREFIX_HINTS
  /opt/homebrew
  /usr/local
  /opt/local
)

# Find header
find_path(Check_INCLUDE_DIR
  NAMES check.h
  HINTS
    ${_CHECK_HINT_INCLUDE}
    ${PC_CHECK_INCLUDEDIR}
    ${PC_CHECK_INCLUDE_DIRS}
  PATHS
    ${_CHECK_PREFIX_HINTS}
  PATH_SUFFIXES
    include
)

# Find library
find_library(Check_LIBRARY
  NAMES check
  HINTS
    ${_CHECK_HINT_LIB}
    ${PC_CHECK_LIBDIR}
    ${PC_CHECK_LIBRARY_DIRS}
  PATHS
    ${_CHECK_PREFIX_HINTS}
  PATH_SUFFIXES
    lib
    lib64
)

# (Optional) compat library (older distros)
find_library(Check_COMPAT_LIBRARY
  NAMES compat
  HINTS
    ${_CHECK_HINT_LIB}
    ${PC_CHECK_LIBDIR}
    ${PC_CHECK_LIBRARY_DIRS}
  PATHS
    ${_CHECK_PREFIX_HINTS}
  PATH_SUFFIXES
    lib
    lib64
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Check
  REQUIRED_VARS Check_LIBRARY Check_INCLUDE_DIR
)

if(Check_FOUND)
  set(Check_INCLUDE_DIRS "${Check_INCLUDE_DIR}")
  if(Check_COMPAT_LIBRARY)
    set(Check_LIBRARIES "${Check_LIBRARY};${Check_COMPAT_LIBRARY}")
  else()
    set(Check_LIBRARIES "${Check_LIBRARY}")
  endif()

  if(NOT TARGET Check::Check)
    add_library(Check::Check UNKNOWN IMPORTED)
    set_target_properties(Check::Check PROPERTIES
      IMPORTED_LOCATION "${Check_LIBRARY}"
      INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIR}"
    )
    if(Check_COMPAT_LIBRARY)
      set_property(TARGET Check::Check APPEND PROPERTY
        INTERFACE_LINK_LIBRARIES "${Check_COMPAT_LIBRARY}"
      )
    endif()
  endif()
endif()

# Backward-compatible variable names used by older projects
set(CHECK_FOUND        "${Check_FOUND}")
set(CHECK_INCLUDE_DIR  "${Check_INCLUDE_DIR}")
set(CHECK_INCLUDE_DIRS "${Check_INCLUDE_DIRS}")
set(CHECK_LIBRARIES    "${Check_LIBRARIES}")

mark_as_advanced(Check_INCLUDE_DIR Check_LIBRARY Check_COMPAT_LIBRARY)
mark_as_advanced(CHECK_INCLUDE_DIR CHECK_LIBRARIES CHECK_INCLUDE_DIRS CHECK_FOUND)