call setupenv.bat

set INSTALL_DIR=%ROOT%\install

IF NOT EXIST "%INSTALL_DIR%" (
  mkdir %INSTALL_DIR%
  mkdir %INSTALL_DIR%\bin
  mkdir %INSTALL_DIR%\lib
  mkdir %INSTALL_DIR%\Plugins
  mkdir %INSTALL_DIR%\Resources
  mkdir %INSTALL_DIR%\tmp
)

rem ## Python
IF NOT EXIST "%INSTALL_DIR%\lib\python38.zip" (
  powershell -nologo -noprofile -command "Invoke-WebRequest 'https://www.python.org/ftp/python/3.8.3/python-3.8.3-embed-amd64.zip' -OutFile '%INSTALL_DIR%\tmp\python-3.8.3-embed-amd64.zip'
  powershell -command "Expand-Archive -Force '%INSTALL_DIR%\tmp\python-3.8.3-embed-amd64.zip' '%INSTALL_DIR%\tmp'"
)
copy %INSTALL_DIR%\tmp\Python3.dll %INSTALL_DIR%\bin
copy %INSTALL_DIR%\tmp\Python38.dll %INSTALL_DIR%\bin

copy %PYTHON_ROOT%\Lib\site-packages\PySide2\pyside2.abi3.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\shiboken2\shiboken2.abi3.dll %INSTALL_DIR%\bin

copy %INSTALL_DIR%\tmp\python38.zip %INSTALL_DIR%\lib

IF NOT EXIST "%INSTALL_DIR%\Plugins\PySide2" (
  mkdir %INSTALL_DIR%\Plugins\PySide2
)
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\__init__.py %INSTALL_DIR%\Plugins\PySide2
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\QtCore.pyd %INSTALL_DIR%\Plugins\PySide2
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\QtGui.pyd %INSTALL_DIR%\Plugins\PySide2
rem copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Core.dll %INSTALL_DIR%\Plugins\PySide2
IF NOT EXIST "%INSTALL_DIR%\Plugins\shiboken2" ( mkdir %INSTALL_DIR%\Plugins\shiboken2 )
copy %PYTHON_ROOT%\Lib\site-packages\shiboken2\__init__.py %INSTALL_DIR%\Plugins\shiboken2
copy %PYTHON_ROOT%\Lib\site-packages\shiboken2\shiboken2.pyd %INSTALL_DIR%\Plugins\shiboken2


rem ## Executable and dependencies
copy %ROOT%\App\x64\release\natron.exe %INSTALL_DIR%\bin
copy %ROOT%\PythonBin\x64\release\natron-python.exe %INSTALL_DIR%\bin
copy %ROOT%\Renderer\x64\release\natronrenderer.exe %INSTALL_DIR%\bin

copy %ROOT%\libs\build\lib\boost_serialization-vc142-mt-x64-1_73.dll %INSTALL_DIR%\bin
copy %ROOT%\libs\build\bin\cairo.dll %INSTALL_DIR%\bin
copy %ROOT%\libs\build\bin\libexpat.dll %INSTALL_DIR%\bin
copy %ROOT%\libs\build\bin\libpng16.dll %INSTALL_DIR%\bin
copy %ROOT%\libs\build\bin\zlib1.dll %INSTALL_DIR%\bin


rem ## QT5
if NOT EXIST "%INSTALL_DIR%\bin\platforms" (
  mkdir %INSTALL_DIR%\bin\platforms
)
rem copy %QT5_ROOT%\bin\Qt5OpenGL.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\bin\Qt5Widgets.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\bin\Qt5Gui.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\bin\Qt5Network.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\bin\Qt5Concurrent.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\bin\Qt5Core.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\bin\Qt5Qml.dll %INSTALL_DIR%\bin
rem copy %QT5_ROOT%\plugins\platforms\qwindows.dll %INSTALL_DIR%\bin\platforms

copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5OpenGL.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Widgets.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Gui.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Network.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Concurrent.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Core.dll %INSTALL_DIR%\bin
copy %PYTHON_ROOT%\Lib\site-packages\PySide2\Qt5Qml.dll %INSTALL_DIR%\bin

copy %PYTHON_ROOT%\Lib\site-packages\PySide2\plugins\platforms\qwindows.dll %INSTALL_DIR%\bin\platforms


rem ## Open ssl
copy %OPENSSL_ROOT%\bin\libcrypto-1_1-x64.dll %INSTALL_DIR%\bin
copy %OPENSSL_ROOT%\bin\libssl-1_1-x64.dll %INSTALL_DIR%\bin


rem ## Resources
if NOT EXIST "%INSTALL_DIR%\Resources\etc" (
  mkdir %INSTALL_DIR%\Resources\etc
  mkdir %INSTALL_DIR%\Resources\etc\fonts
  mkdir %INSTALL_DIR%\Resources\etc\fonts\conf.d
)
xcopy /E /Y %ROOT%\libs\fontconfig\fontconfig\conf.d %INSTALL_DIR%\Resources\etc\fonts\conf.d\
copy %ROOT%\libs\fontconfig\fontconfig\SMP\fonts.conf %INSTALL_DIR%\Resources\etc\fonts
del %INSTALL_DIR%\Resources\etc\fonts\conf.d\Makefile.am
del %INSTALL_DIR%\Resources\etc\fonts\conf.d\README.in

if NOT EXIST "%INSTALL_DIR%\Resources\OpenColorIO-Configs" (
  mkdir %INSTALL_DIR%\Resources\OpenColorIO-Configs
)
xcopy /E /Y %ROOT%\OpenColorIO-Configs\blender %INSTALL_DIR%\Resources\OpenColorIO-Configs\blender\
xcopy /E /Y %ROOT%\OpenColorIO-Configs\natron %INSTALL_DIR%\Resources\OpenColorIO-Configs\natron\
xcopy /E /Y %ROOT%\OpenColorIO-Configs\nuke-default %INSTALL_DIR%\Resources\OpenColorIO-Configs\nuke-default\

xcopy /E /Y %ROOT%\Gui\Resources\PyPlugs %INSTALL_DIR%\Plugins\PyPlugs\

pause
exit /b