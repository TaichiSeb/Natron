call :ABSOLUTE_PATH ROOT %~dp0..\..

set OPENSSL_ROOT=c:\softs\openssl
set QT5_ROOT=E:\projets\qt5\qt5install
set PYTHON_ROOT=C:\softs\Python38

exit /b

:ABSOLUTE_PATH
SET %1=%~f2
exit /b
