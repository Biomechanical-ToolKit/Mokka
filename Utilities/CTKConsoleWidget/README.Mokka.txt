11/27/2013
----------
The code in this folder is adapted from CTK (commontk-CTK-46a1d66055) to keep only the code used for the Python console. 
When necessary, the code was adapted to work with Qt5:

 - Qt Signal/slot connections replaced with the new Qt5 style
 - File ctkWidgetsExport.h was generated manually (no need of the export symbol)
 - File ctkScriptingPythonCoreExport.h was generated manually (no need of the export symbol)
 - File ctkScriptingPythonWidgetsExport.h was generated manually (no need of the export symbol)
 - File ctkScriptingPythonCoreConfigure.h was generated manually (no need of the defined symbols)
 - The Python console has no more a default windows icon as this one is not included (ctkPythonConsole.cpp, lines 314)
 - No need of the header QDebug in the file ctkAbstractPythonManager.cpp (line 23)
 - No need of the header QDebug in the file ctkConsole.cpp (line 61)
 - Due to the remove of the header QDebug, the qWarning commands were adapted to use the "fprintf" style.
 - Clang complains about the used of <angled> instead of "quotes" in ctkPythonConsole.h (line 55 - #include <ctkConsole.h>)
 - All the call to ".toAscii().data()" were replaced by qPrintable