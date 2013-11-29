FIND_PACKAGE(Qt5 REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)

IF(MOKKA_USE_PYTHON)
  FIND_PACKAGE(PythonLibs REQUIRED)
  # FIND_PACKAGE(PythonQt REQUIRED)
  # TODO: Create a FindPythonQt.cmake (or PythonQtConfig.cmake)
  IF((NOT PYTHONQT_INCLUDE_DIR) OR (NOT PYTHONQT_GENERATED_CPP_DIR) OR (NOT PYTHONQT_LIBRARIES))
    set(PYTHONQT_INCLUDE_DIR NOTFOUND CACHE PATH "Path containing the headers of PythonQt.")
    set(PYTHONQT_GENERATED_CPP_DIR NOTFOUND CACHE PATH "Path containing the generated headers of PythonQt.")
    set(PYTHONQT_LIBRARIES NOTFOUND CACHE FILEPATH "Path containing the libraries of PythonQt.")
    MESSAGE(FATAL_ERROR "\nPlease set the paths for PythonQt:\n- PYTHONQT_INCLUDE_DIR\n- PYTHONQT_GENERATED_CPP_DIR\n- PYTHONQT_LIBRARIES")
  ENDIF()
ENDIF()

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/qMokkaConfigure.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/qMokkaConfigure.h @ONLY IMMEDIATE)

INCLUDE_DIRECTORIES(
        "${CMAKE_CURRENT_SOURCE_DIR}/Core"
        "${CMAKE_CURRENT_SOURCE_DIR}/Python"
        "${CMAKE_CURRENT_SOURCE_DIR}/UI"
        "${MOKKA_SOURCE_DIR}/Utilities/ParserCmdLine"
        ${PYTHON_INCLUDE_PATH}
        ${PYTHONQT_INCLUDE_DIR}
        ${PYTHONQT_GENERATED_CPP_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

SET(Mokka_CPP
  main.cpp
  qMokkaApplication.cpp
  # Core
  Core/qMokkaCoreApplication.cpp
  Core/qMokkaCorePythonManager.cpp
  )
  
SET(Mokka_H
  qMokkaApplication.h
  # Core
  Core/qMokkaCoreApplication.h
  )

IF(MOKKA_USE_PYTHON)  
  INCLUDE_DIRECTORIES("${MOKKA_SOURCE_DIR}/Utilities/CTKConsoleWidget")
  SET(Mokka_CPP
    ${Mokka_CPP}
    Python/qMokkaPythonManager.cpp
    Python/qMokkaPythonConsole.cpp
    ../Utilities/CTKConsoleWidget/ctkConsole.cpp
    ../Utilities/CTKConsoleWidget/ctkPythonConsole.cpp
    ../Utilities/CTKConsoleWidget/ctkAbstractPythonManager.cpp
  )
  SET(Mokka_H
    ${Mokka_H}
    Python/qMokkaPythonConsole.h
    ../Utilities/CTKConsoleWidget/ctkConsole.h
    ../Utilities/CTKConsoleWidget/ctkConsole_p.h
    ../Utilities/CTKConsoleWidget/ctkPythonConsole.h
    ../Utilities/CTKConsoleWidget/ctkAbstractPythonManager.h
    )
ENDIF()

QT5_WRAP_CPP(Mokka_MOC ${Mokka_H})

ADD_EXECUTABLE(Mokka ${Mokka_MOC} ${Mokka_CPP})

TARGET_LINK_LIBRARIES(Mokka ${PYTHON_LIBRARIES} ${PYTHONQT_LIBRARIES})

QT5_USE_MODULES(Mokka Widgets)

ADD_CUSTOM_COMMAND(TARGET Mokka PRE_LINK
                   COMMAND ${CMAKE_COMMAND} -E copy_directory "${MOKKA_SOURCE_DIR}/Scripting" "${MOKKA_EXECUTABLE_PATH}/Script")


