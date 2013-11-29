# - Try to find Qt5
# Once done this will define
#
#  Qt5_ROOT_PATH: Root path for the CMake folder included in Qt5
#  Qt5_CMAKE_PATH: Root path for the CMake folder included in Qt5
#  Qt5_FOUND: Simple flag to indicate if Qt5 was found or not
#
# Note: This only attempt to add the path in the variable CMAKE_PREFIX_PATH
#       to be able to use after the CMake scripts provided by Qt5.
#
# Copyright (c) 2009-2013 Arnaud Barré <arnaud.barre@gmail.com>
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file

IF(Qt5_ROOT_PATH)
   # In cache already
   SET(Qt5_FIND_QUIETLY TRUE)
ENDIF(Qt5_ROOT_PATH)

IF(APPLE)
  FILE(GLOB Qt5_PATHS_A "/Developer/Qt5*")
  FILE(GLOB Qt5_PATHS_B "/Developer/Qt/5*")
  FILE(GLOB Qt5_PATHS_C "$ENV{HOME}/Qt/5*")
  FILE(GLOB Qt5_PATHS_D "$ENV{HOME}/Developer/Qt/5*")
  SET(Qt_PATH_SUFFIXES "clang_64")
  SET(Qt_QMAKE "qmake")
ELSEIF(WIN32)
  FILE(GLOB Qt5_PATHS_A "C:/Qt/Qt5*/*")
  SET(Qt_PATH_SUFFIXES "msvc2010_opengl")
  SET(Qt_QMAKE "qmake.exe")
ENDIF(APPLE)

FIND_PATH(Qt5_ROOT_PATH NAMES bin/${Qt_QMAKE}
     PATH_SUFFIXES  ${Qt_PATH_SUFFIXES}
     NO_DEFAULT_PATH
     HINTS
     ${Qt5_PATHS_A}
     ${Qt5_PATHS_B}
     ${Qt5_PATHS_C}
     ${Qt5_PATHS_D}
   )

IF(Qt5_ROOT_PATH)
  SET(Qt5_FOUND 1)
ENDIF(Qt5_ROOT_PATH)
  
SET (Qt5_CMAKE_PATH "${Qt5_ROOT_PATH}/lib/cmake")
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Qt5 DEFAULT_MSG Qt5_ROOT_PATH)

LIST(FIND CMAKE_PREFIX_PATH ${Qt5_CMAKE_PATH} _Qt5_PATH_INDEX)
IF(_Qt5_PATH_INDEX EQUAL -1)
  SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${Qt5_CMAKE_PATH})
ENDIF(_Qt5_PATH_INDEX EQUAL -1)
MARK_AS_ADVANCED(Qt5_ROOT_PATH CMAKE_PREFIX_PATH)