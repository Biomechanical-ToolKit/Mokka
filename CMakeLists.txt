CMAKE_MINIMUM_REQUIRED(VERSION 2.8.9)

PROJECT(MOKKA)

SET(MOKKA_VERSION_MAJOR 0)
SET(MOKKA_VERSION_MINOR 7)
SET(MOKKA_VERSION_PATCH 0)
IF(MOKKA_VERSION_PATCH EQUAL 0)
  SET(MOKKA_VERSION_STRING "${MOKKA_VERSION_MAJOR}.${MOKKA_VERSION_MINOR}")
ELSE()
  SET(MOKKA_VERSION_STRING "${MOKKA_VERSION_MAJOR}.${MOKKA_VERSION_MINOR}.${MOKKA_VERSION_PATCH}")
ENDIF()

# ------------------------------------------------------------------------
# COMPILATION INSTRUCTIONS
# ------------------------------------------------------------------------

# Using the configuration "Always full RPATH"
# from http://www.cmake.org/Wiki/CMake_RPATH_handling
#             --------------------------
# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
# the RPATH to be used when installing
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# By default Mokka is compiled in Release mode
IF(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  MESSAGE(STATUS "Setting build type to 'Release' as none was specified.")
  SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
ENDIF(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)

# Output directories.
IF(NOT LIBRARY_OUTPUT_PATH)
  SET (LIBRARY_OUTPUT_PATH ${MOKKA_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
ENDIF(NOT LIBRARY_OUTPUT_PATH)
IF(NOT EXECUTABLE_OUTPUT_PATH)
  SET (EXECUTABLE_OUTPUT_PATH ${MOKKA_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")
ENDIF(NOT EXECUTABLE_OUTPUT_PATH)
SET(MOKKA_LIBRARY_PATH "${LIBRARY_OUTPUT_PATH}")
SET(MOKKA_EXECUTABLE_PATH "${EXECUTABLE_OUTPUT_PATH}")

SET(MOKKA_CMAKE_MODULE_PATH "${MOKKA_SOURCE_DIR}/CMake")
SET(CMAKE_MODULE_PATH "${MOKKA_CMAKE_MODULE_PATH}")

# ------------------------------------------------------------------------
# PROJECT SETUP
# ------------------------------------------------------------------------

OPTION(MOKKA_USE_PYTHON "Active the Python console in Mokka (require PythonQt)" TRUE)

# ------------------------------------------------------------------------
# PROJECT'S SUBDIRECTORIES
# ------------------------------------------------------------------------

# Code
ADD_SUBDIRECTORY(Code)