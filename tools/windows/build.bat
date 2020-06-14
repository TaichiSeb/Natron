@echo off
rem ##########################################
rem # get and build Natron dependencies and then build Natron
rem ##########################################
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

call setupenv.bat
set CYGWIN_ROOT=e:\cygwin64

cd %ROOT%
echo "Updating submodules"
git submodule update -r -i

rem pour builder Qt5 : 
rem "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
rem PATH=%PYTHON_ROOT%;%PYTHON_ROOT%\Scripts;%OPENSSL_ROOT%\bin;%PATH%
rem dans un repertoire au meme niveau que les sources qt5
rem E:\projets\qt5\qt5build>..\qt5\configure -opensource -confirm-license -mp -nomake examples -nomake tests -prefix E:\projets\qt5\qt5install -openssl-linked OPENSSL_LIBS="-llibssl -llibcrypto" -I c:\softs\openssl\include -L c:\softs\openssl\lib
rem nmake

rem pour builder pyside-setup :
rem get clone https://code.qt.io/cgit/pyside/pyside-setup.git tag 5.15.0
rem "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
rem wget https://download.qt.io/development_releases/prebuilt/libclang/qt/libclang-release_100-based-windows-vs2019_64.7z
rem set PATH=%QT5_ROOT%\bin;%PYTHON_ROOT%;%PYTHON_ROOT%\Scripts;%OPENSSL_ROOT%\bin;E:\projets\pyside-setup\libclang\bin;%PATH%
rem python setup.py build --qmake=E:\projets\qt5\qt5install\bin\qmake.exe --openssl=c:\softs\openssl\bin --ignore-git
rem python setup.py install --qmake=E:\projets\qt5\qt5install\bin\qmake.exe --openssl=c:\softs\openssl\bin --ignore-git
rem ou bien
rem mkdir build
rem cmake -S. -B.\build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=.\install
rem msbuild build\pyside2_super_project.sln /m /p:useenv=true;Configuration=Release;Platform=x64
rem msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64

rem ### prerequis
cd %ROOT%\libs

IF NOT EXIST "build" (
  mkdir build
  mkdir build\lib
  mkdir build\include
  mkdir build\bin
  mkdir build\downloads
)

set INCLUDE=%ROOT%\libs\build\include;%INCLUDE%
set LIB=%ROOT%\libs\build\lib;%LIB%

set FONTCONFIG_PATH=%ROOT%\libs\build\fonts

set PATH=%PYTHON_ROOT%;%PYTHON_ROOT%\Scripts;%PYTHON_ROOT%\Lib\site-packages\shiboken2;%PYTHON_ROOT%\Lib\site-packages\PySide2;%OPENSSL_ROOT%\bin;%PATH%
set PATH=%ROOT%\libs\build\bin;%ROOT%\libs\build\lib;%QT5_ROOT%\bin;%PATH%

pip install numpy lxml pip PySide2 setuptools shiboken2 shiboken2-generator wheel pytest PyOpenGL pyinstaller six sphinx --upgrade

set ZLIB_SOURCE_ROOT=zlib-1.2.11
IF EXIST %ZLIB_SOURCE_ROOT% (
  echo "Zlib is available"
) ELSE (
  echo "Downloading zlib"
  powershell -nologo -noprofile -command "Invoke-WebRequest 'https://zlib.net/zlib1211.zip' -OutFile build\downloads\zlib1211.zip"
  powershell -command "Expand-Archive -Force 'build\downloads\zlib1211.zip' '.'"
)

set TIFF_SOURCE_ROOT=libtiff
IF EXIST %TIFF_SOURCE_ROOT% (
  echo "Libtiff is available"
) ELSE (
  echo "Downloading libtiff"
  git clone https://gitlab.com/libtiff/libtiff.git %TIFF_SOURCE_ROOT%
  cd %TIFF_SOURCE_ROOT%
  git checkout --quiet tags/v4.1.0
  cd %ROOT%\libs
)

set LIB_PNG_SOURCE_ROOT=libpng
IF EXIST %LIB_PNG_SOURCE_ROOT% (
  echo "Libpng is available"
) ELSE (
  echo "Downloading libpng"
  git clone https://github.com/glennrp/libpng.git %LIB_PNG_SOURCE_ROOT%
  cd %LIB_PNG_SOURCE_ROOT%
  git checkout --quiet tags/v1.6.37
  cd %ROOT%\libs
)

set LIB_JPEG_SOURCE_ROOT=jpeg-9d
IF EXIST %LIB_JPEG_SOURCE_ROOT% (
  echo "Libjpeg is available"
) ELSE (
  echo "Downloading libjpeg"
  powershell -nologo -noprofile -command "Invoke-WebRequest 'http://ijg.org/files/jpegsr9d.zip' -OutFile build\downloads\jpegsr9d.zip"
  powershell -command "Expand-Archive -Force 'build\downloads\jpegsr9d.zip' '.'"
)

set CURL_SOURCE_ROOT=cURL
IF EXIST %CURL_SOURCE_ROOT% (
  echo "cURL is available"
) ELSE (
  echo "Downloading cURL"
  git clone https://github.com/curl/curl.git %CURL_SOURCE_ROOT%
  cd %CURL_SOURCE_ROOT%
  git checkout --quiet tags/curl-7_70_0
  mkdir ..\deps
  cd %ROOT%\libs
)

set OPEN_EXR_SOURCE_ROOT=openEXR
IF EXIST %OPEN_EXR_SOURCE_ROOT% (
  echo "open EXR is available"
) ELSE (
  echo "Downloading open EXR"
  git clone https://github.com/AcademySoftwareFoundation/openexr.git %OPEN_EXR_SOURCE_ROOT%
  cd %OPEN_EXR_SOURCE_ROOT%
  git checkout --quiet tags/v2.5.1
  cd %ROOT%\libs
)

set GLEW_SOURCE_ROOT=glew
IF EXIST %GLEW_SOURCE_ROOT% (
  echo "glew is available"
) ELSE (
  echo "Downloading glew"
  git clone https://github.com/nigels-com/glew.git %GLEW_SOURCE_ROOT%
  rem latest tag (2.1.0) is too old and won't build on windows !
  rem cd %GLEW_SOURCE_ROOT%
  rem git checkout --quiet tags/glew-2.1.0
  rem cd %ROOT%\libs
)

set BOOST_SOURCE_ROOT=boost_1_73_0
IF EXIST %BOOST_SOURCE_ROOT% (
  echo "boost is available"
) ELSE (
  echo "Downloading boost"
  git clone https://github.com/boostorg/boost.git %BOOST_SOURCE_ROOT%
  cd %BOOST_SOURCE_ROOT%
  git checkout --quiet tags/boost-1.73.0
  git submodules update -i -r
  cd %ROOT%\libs
)

set PYBIND11_SOURCE_ROOT=PyBind11
IF EXIST %PYBIND11_SOURCE_ROOT% (
  echo "PyBind11 is available"
) ELSE (
  echo "Downloading PyBind11"
  git clone https://github.com/pybind/pybind11.git %PYBIND11_SOURCE_ROOT%
  cd %PYBIND11_SOURCE_ROOT%
  git checkout --quiet tags/v2.5.0
  cd %ROOT%\libs
)

rem ## TODO : optional deps for OpenImageIO
rem https://ffmpeg.zeranoe.com/builds/win64/static/ffmpeg-4.2.3-win64-static.zip
rem https://ffmpeg.zeranoe.com/builds/win64/dev/ffmpeg-4.2.3-win64-dev.zip
rem https://ffmpeg.zeranoe.com/builds/win64/shared/ffmpeg-4.2.3-win64-shared.zip
rem https://github.com/LibRaw/LibRaw tags/0.19.5
rem https://github.com/strukturag/libheif tags/v1.7.0
rem https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_0/source/CMake-hdf5-1.12.0.zip
rem https://github.com/wdas/ptex tags/v2.3.2

set OPENIMAGEIO_SOURCE_ROOT=OpenImageIO
IF EXIST %OPENIMAGEIO_SOURCE_ROOT% (
  echo "open image IO is available"
) ELSE (
  echo "Downloading open image IO"
  git clone https://github.com/OpenImageIO/oiio.git %OPENIMAGEIO_SOURCE_ROOT%
  cd %OPENIMAGEIO_SOURCE_ROOT%
  git checkout --quiet branches/release
  cd %ROOT%\libs
)

set OPENCOLORIO_SOURCE_ROOT=OpenColorIO
IF EXIST %OPENCOLORIO_SOURCE_ROOT% (
  echo "open color IO is available"
) ELSE (
  echo "Downloading open color IO"
  git clone https://github.com/AcademySoftwareFoundation/OpenColorIO.git %OPENCOLORIO_SOURCE_ROOT%
  cd %OPENCOLORIO_SOURCE_ROOT%
  git checkout --quiet tags/v1.1.1
  cd %ROOT%\libs
)

set PIXMAN_SOURCE_ROOT=pixman
IF EXIST %PIXMAN_SOURCE_ROOT% (
  echo "pixman is available"
) ELSE (
  echo "Downloading pixman"
  git clone https://gitlab.freedesktop.org/pixman/pixman.git %PIXMAN_SOURCE_ROOT%
  cd %PIXMAN_SOURCE_ROOT%
  git checkout --quiet tags/pixman-0.40.0
  cd %ROOT%\libs
)

set CAIRO_SOURCE_ROOT=cairo
IF EXIST %CAIRO_SOURCE_ROOT% (
  echo "cairo is available"
) ELSE (
  echo "Downloading cairo"
  git clone https://gitlab.freedesktop.org/cairo/cairo.git %CAIRO_SOURCE_ROOT%
  cd %CAIRO_SOURCE_ROOT%
  git checkout --quiet tags/1.17.2
  cd %ROOT%\libs
)

set LIBEXPAT_SOURCE_ROOT=libexpat
IF EXIST %LIBEXPAT_SOURCE_ROOT% (
  echo "libexpat is available"
) ELSE (
  echo "Downloading libexpat"
  git clone https://github.com/libexpat/libexpat %LIBEXPAT_SOURCE_ROOT%
  cd %LIBEXPAT_SOURCE_ROOT%
  git checkout --quiet tags/R_2_2_9
  cd %ROOT%\libs
)

set FONTCONFIG_SOURCE_ROOT=fontconfig\fontconfig
IF EXIST %FONTCONFIG_SOURCE_ROOT% (
  echo "fontconfig is available"
) ELSE (
  echo "Downloading fontconfig"
  rem git clone https://github.com/freedesktop/fontconfig.git %FONTCONFIG_SOURCE_ROOT%
  git clone https://github.com/ShiftMediaProject/fontconfig %FONTCONFIG_SOURCE_ROOT%
  cd %FONTCONFIG_SOURCE_ROOT%
  git checkout --quiet tags/2.13.1
  cd %ROOT%\libs
)

rem #############################################

IF EXIST "%ROOT%\libs\build\lib\libfontconfig.lib" (
  echo "fontconfig is already built"
) ELSE (
  cd %ROOT%\libs\%FONTCONFIG_SOURCE_ROOT%\SMP
  call project_get_dependencies.bat nul
  devenv libfontconfig_deps.sln /upgrade
  msbuild libfontconfig_deps.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  devenv libfontconfig.sln /upgrade
  msbuild libfontconfig.sln /m /p:useenv=true;Configuration=Release;Platform=x64

  xcopy /E /Y ..\..\..\msvc\include %ROOT%\libs\build\include\
  copy ..\..\..\msvc\lib\x64\libfontconfig.lib %ROOT%\libs\build\lib
  copy ..\..\..\msvc\lib\x64\libfreetype.lib %ROOT%\libs\build\lib
  copy ..\..\..\msvc\lib\x64\libiconv.lib %ROOT%\libs\build\lib
  copy ..\..\..\msvc\lib\x64\liblzma.lib %ROOT%\libs\build\lib
  copy ..\..\..\msvc\lib\x64\libxml2.lib %ROOT%\libs\build\lib
)

IF EXIST "%ROOT%\libs\build\lib\libexpat.lib" (
  echo "libexpat is already built"
) ELSE (
  echo "Building libexpat"
  cd %ROOT%\libs\%LIBEXPAT_SOURCE_ROOT%\expat
  cmake -S. -B.\build -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=%ROOT%\libs\build -DEXPAT_MSVC_STATIC_CRT:BOOL=OFF
  rem devenv expat.sln /upgrade
  msbuild build\expat.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
)

IF EXIST "%ROOT%\libs\build\lib\zlib.lib" (
  echo "zlib is already built"
) ELSE (
  echo "Building zlib"
  cd %ROOT%\libs\%ZLIB_SOURCE_ROOT%
  nmake -f win32\Makefile.msc
  copy zdll.lib ..\build\lib
  copy zlib.lib ..\build\lib
  copy *.h ..\build\include
  copy zlib1.dll ..\build\bin
)

IF EXIST "%ROOT%\libs\build\lib\libtiff.lib" (
  echo "libtiff is already built"
) ELSE (
  echo "Building libtiff"
  cd %ROOT%\libs\%TIFF_SOURCE_ROOT%
  nmake -f Makefile.vc
  copy libtiff\*.lib ..\build\lib
  copy libtiff\*.dll ..\build\bin
  copy libtiff\*.h ..\build\include
)

IF EXIST "%ROOT%\libs\build\lib\libpng16.lib" (
  echo "libpng is already built"
) ELSE (
  echo "Building libpng"
  cd %ROOT%\libs\%LIB_PNG_SOURCE_ROOT%
  cmake -S. -B.\build -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=..\build
  msbuild build\libpng.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
  copy %ROOT%\libs\build\lib\libpng16.lib %ROOT%\libs\build\lib\libpng.lib
)

IF EXIST "%ROOT%\libs\build\lib\jpeg.lib" (
  echo "libjpeg is already built"
) ELSE (
  echo "Building libjpeg"
  cd %ROOT%\libs\%LIB_JPEG_SOURCE_ROOT%
  NMAKE /f makefile.vs setupcopy-v16
  msbuild jpeg.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  copy *.h ..\build\include
  copy Release\x64\jpeg.lib ..\build\lib
)

IF EXIST "%ROOT%\libs\build\lib\libboost_serialization-vc142-mt-gd-x64-1_73.lib" (
  echo "boost is already built"
) ELSE (
  echo "Building boost"
  cd %ROOT%\libs\%BOOST_SOURCE_ROOT%
  call bootstrap.bat
  .\b2 -a -j 4 --build-dir=build --without-mpi --without-graph_parallel --build-type=complete --prefix=%ROOT%\libs\build address-model=64 threading=multi install
  move %ROOT%\libs\build\include\boost-1_73\boost %ROOT%\libs\build\include\boost
)

IF EXIST "%ROOT%\libs\build\lib\libcurl_a.lib" (
  echo "cURL is already built"
) ELSE (
  echo "Building cURL"
  cd %ROOT%\libs\%CURL_SOURCE_ROOT%

  xcopy /E /Y %OPENSSL_ROOT%\include ..\deps\include\
  xcopy /E /Y %OPENSSL_ROOT%\lib ..\deps\lib\
  copy %ROOT%\libs\%ZLIB_SOURCE_ROOT%\*.h ..\deps\include
  copy %ROOT%\libs\%ZLIB_SOURCE_ROOT%\zlib.lib ..\deps\lib

  call buildconf.bat
  cd winbuild
  nmake /f Makefile.vc mode=static WITH_SSL=dll WITH_ZLIB=static
  cd ..
  xcopy /E /Y builds\libcurl-vc-x64-release-static-ipv6-sspi-winssl\bin ..\build\bin
  xcopy /E /Y builds\libcurl-vc-x64-release-static-ipv6-sspi-winssl\include ..\build\include
  xcopy /E /Y builds\libcurl-vc-x64-release-static-ipv6-sspi-winssl\lib ..\build\lib
)

IF EXIST "%ROOT%\libs\build\lib\IlmImf-2_5.lib" (
  echo "open EXR is already built"
) ELSE (
  echo "Building open EXR"
  cd %ROOT%\libs\%OPEN_EXR_SOURCE_ROOT%
  cmake -S. -B.\build -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=..\build
  msbuild build\OpenEXRMetaProject.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
)

IF EXIST "%ROOT%\libs\build\lib\glew32.lib" (
  echo "glew is already built"
) ELSE (
  call :BUILD_GLEW
)

IF EXIST "%ROOT%\libs\build\include\pybind11\pybind11.h" (
  echo "PyBind11 is already built"
) ELSE (
  echo "Building PyBind11"
  cd %ROOT%\libs\%PYBIND11_SOURCE_ROOT%
  cmake -S. -B.\build -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=..\build
  msbuild build\PyBind11.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
)

IF EXIST "%ROOT%\libs\build\lib\OpenImageIO.lib" (
  echo "open image IO is already built"
) ELSE (
  echo "Building open image IO"
  cd %ROOT%\libs\%OPENIMAGEIO_SOURCE_ROOT%
  cmake -S. -B.\build -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=..\build
  msbuild build\OpenImageIO.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
)

rem patcher OpenColorIO\share\cmake\OCIOMacros.cmake pour trouver python
rem patcher src\pyglue\PyUtil.h : remplacer le define de MOD_INIT par #define MOD_INIT(name) PyMODINIT_FUNC PyInit_##name(void)
rem patcher CMakeList.txt avec :
rem enable_language(CXX)
rem
rem if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
rem   set(CMAKE_CXX_STANDARD 14)
rem   set(CMAKE_CXX_STANDARD_REQUIRED ON)
rem   set(CMAKE_CXX_EXTENSIONS OFF)
rem   add_compile_options("/Zc:__cplusplus")
rem endif()
rem ## attention, cmake a tendance a prendre les libs glut 32 bits au lieu des 64 bits pour CG
IF EXIST "%ROOT%\libs\build\lib\OpenColorIO.lib" (
  echo "open color IO is already built"
) ELSE (
  echo "Building open color IO"
  cd %ROOT%\libs\%OPENCOLORIO_SOURCE_ROOT%
  cmake -S. -B.\build -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=..\build
  msbuild build\OpenColorIO.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild build\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
)

IF EXIST "%ROOT%\libs\build\lib\pixman-1.lib" (
  echo "pixman is already built"
) ELSE (
  call :BUILD_PIXMAN
)

IF EXIST "%ROOT%\libs\build\lib\cairo.lib" (
  echo "cairo is already built"
) ELSE (
  call :BUILD_CAIRO
)

set NATRON_OPENCOLORIO_CONFIGS_VERSION=2.3
IF EXIST "%ROOT%\OpenColorIO-Configs" (
  echo OpenColorIO configs are already downloaded
) ELSE (
  echo Download and install OpenColorIO configs
  cd %ROOT%
  powershell -nologo -noprofile -command "Invoke-WebRequest 'https://github.com/NatronGitHub/OpenColorIO-Configs/archive/Natron-v%NATRON_OPENCOLORIO_CONFIGS_VERSION%.tar.gz' -OutFile '%ROOT%\Natron-v%NATRON_OPENCOLORIO_CONFIGS_VERSION%.tar.gz'
  powershell -command "tar -xf '%ROOT%\Natron-v%NATRON_OPENCOLORIO_CONFIGS_VERSION%.tar.gz'"
  move OpenColorIO-Configs-Natron-v%NATRON_OPENCOLORIO_CONFIGS_VERSION% OpenColorIO-Configs
)

cd %ROOT%
echo Generating config.pri file
echo 64bit { > config.pri
echo   boost {>> config.pri
echo     INCLUDEPATH +=  $$quote(%ROOT%\libs\build\include) >> config.pri
echo     CONFIG(release, debug^|release): LIBS += -L$$quote(%ROOT%\libs\build\lib) -lboost_serialization-vc142-mt-x64-1_73 >> config.pri
echo     CONFIG(debug, debug^|release):  LIBS += -L$$quote(%ROOT%\libs\build\lib) -lboost_serialization-vc142-mt-gd-x64-1_73 >> config.pri
echo   }>> config.pri
echo   expat {>> config.pri
rem echo     INCLUDEPATH += $$quote(%ROOT%\libs\OpenFX\HostSupport\expat-2.2.9\lib) >> config.pri
rem echo     LIBS += -L$$quote(%ROOT%\libs\OpenFX\HostSupport\expat-2.2.9\win32\bin\Release) -llibexpatMT >> config.pri
echo     INCLUDEPATH += $$quote(%ROOT%\libs\build\include) >> config.pri
echo     LIBS += -L$$quote(%ROOT%\libs\build\lib) -llibexpat >> config.pri
echo     LIBS += shell32.lib >> config.pri
echo   }>> config.pri
echo   cairo {>> config.pri
echo     INCLUDEPATH += $$quote(%ROOT%\libs\build\include) >> config.pri
echo     LIBS += -L$$quote(%ROOT%\libs\build\lib) -lcairo >> config.pri
echo   }>> config.pri
echo   python {>> config.pri
echo     INCLUDEPATH += $$quote(%PYTHON_ROOT%\include) >> config.pri
echo     LIBS += -L$$quote(%PYTHON_ROOT%\libs) -lpython3 >> config.pri
echo   }>> config.pri
echo   pyside {>> config.pri
echo     INCLUDEPATH += $$quote(%PYTHON_ROOT%\Lib\site-packages\PySide2\include) >> config.pri
echo     INCLUDEPATH += $$quote(%PYTHON_ROOT%\Lib\site-packages\PySide2\include\QtGui) >> config.pri
echo     INCLUDEPATH += $$quote(%PYTHON_ROOT%\Lib\site-packages\PySide2\include\QtCore) >> config.pri
echo     INCLUDEPATH += $$quote(%QT5_ROOT%\include\QtGui) >> config.pri
echo     LIBS += -L$$quote(%PYTHON_ROOT%\Lib\site-packages\PySide2) -lpyside2.abi3 >> config.pri
echo   }>> config.pri
echo   shiboken {>> config.pri
echo     INCLUDEPATH += $$quote(%PYTHON_ROOT%\Lib\site-packages\shiboken2_generator\include) >> config.pri
echo     LIBS += -L$$quote(%PYTHON_ROOT%\Lib\site-packages\shiboken2) -lshiboken2.abi3 >> config.pri
echo   }>> config.pri
echo   3rdparties {>> config.pri
echo     INCLUDEPATH += $$quote(%ROOT%\libs\build\include) >> config.pri
echo     LIBS += -L$$quote(%ROOT%\libs\build\lib) -llibfontconfig >> config.pri
echo   }>> config.pri
echo }>> config.pri

powershell -Command "(gc config.pri) -replace '\\', '\\' | Out-File -encoding ASCII config.pri"

rem pour generer les stubs python/C++ avec shiboken2 (ils sont deja livres donc pas necessaire de les regenerer) :
rem E:\projets\natron\Natron>shiboken2  --avoid-protected-hack --enable-pyside-extensions --include-paths=.;E:\projets\natron\Natron\Engine;E:\projets\natron\Natron\Global;C:\softs\Python38\Lib\site-packages\PySide2\include;c:\softs\Pytho38\include;e:\projets\qt5\qt5install\include;E:\projets\natron\Natron\libs\OpenFX\include --typesystem-paths=C:\softs\Python38\Lib\site-packages\PySide2\typesystems --output-directory=Engine Engine\Pyside_Engine_Python.h Engine\typesytem_engine.xml
rem E:\projets\natron\Natron>shiboken2  --avoid-protected-hack --enable-pyside-extensions --include-paths=.;E:\projets\natron\Natron\Engine;E:\projets\natron\Natron\Gui;E:\projets\natron\Natron\Global;C:\softs\Python38\Lib\site-packages\PSide2\include;c:\softs\Python38\include;e:\projets\qt5\qt5install\include;e:\projets\qt5\qt5install\include\QtWidgets;E:\projets\natron\Natron\libs\OpenFX\include;E:\projets\natron\Natron\libs\build\include --typesystem-paths=C:\softsPython38\Lib\site-packages\PySide2\typesystems;Engine --output-directory=Gui Gui\Pyside_Gui_Python.h Gui\typesystem_natronGui.xml

cd %ROOT%
qmake -r -tp vc -spec win32-msvc CONFIG+=64bit CONFIG+=release Project.pro -o Project64.sln
msBuild Project64.sln /m /p:useenv=true;Configuration=Release;Platform=x64 /t:Natron

cd %ROOT%\Tests
msBuild Tests.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
cd %ROOT%\Tests\x64\release
rem pour pouvoir charger PySide2.QtCore il faut que les dependences de QtCore.pyd (QtCore.dll and co) soient celles packagees avec PySide et non celle du Qt local qui n'est pas necessairement de la meme version. On set donc PATH en consequence.
set PATH=%PYTHON_ROOT%\Lib\site-packages\PySide2;%PATH%
Tests.exe

pause
exit /b

:BUILD_GLEW
  echo "Building glew"
  cd %ROOT%\libs\%GLEW_SOURCE_ROOT%
  set PATH_OLD=%PATH%
  set PATH=%CYGWIN_ROOT%\bin;%PATH%
  make extensions
  set PATH=%PATH_OLD%
  set PATH_OLD=
  cmake -Sbuild/cmake -B.\buildseb -G "Visual Studio 16 2019" -Ax64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=..\build
  msbuild buildseb\glew.sln /m /p:useenv=true;Configuration=Release;Platform=x64
  msbuild buildseb\INSTALL.vcxproj /m /p:useenv=true;Configuration=Release;Platform=x64
  exit /b

:BUILD_PIXMAN
  echo "Building pixman"
  cd %ROOT%\libs\%PIXMAN_SOURCE_ROOT%
  set PATH_OLD=%PATH%
  set PATH=%PATH%;%CYGWIN_ROOT%\bin
  dos2unix autogen.sh
  dos2unix configure.ac
  bash ./autogen.sh
  make -f Makefile.win32 "CFG=release" "MMX=off"
  set PATH=%PATH_OLD%
  set PATH_OLD=
  mkdir ..\build\include\pixman-1
  copy pixman\pixman.h ..\build\include\pixman-1
  copy pixman\pixman-version.h ..\build\include\pixman-1
  copy pixman\release\pixman-1.lib ..\build\lib
  exit /b

:BUILD_CAIRO
  cd %ROOT%\libs\%CAIRO_SOURCE_ROOT%
  set PATH_OLD=%PATH%
  set PATH=%PATH%;%CYGWIN_ROOT%\bin
  make -f Makefile.win32 "CFG=release" "LIBPNG_PATH=%ROOT%\libs\build\lib" "ZLIB_PATH=%ROOT%\libs\build\lib"
  set PATH=%PATH_OLD%
  set PATH_OLD=
  mkdir ..\build\include\cairo
  copy src\cairo.h ..\build\include\cairo
  copy src\cairo-deprecated.h ..\build\include\cairo
  copy src\cairo-features.h ..\build\include\cairo
  copy src\cairo-pdf.h ..\build\include\cairo
  copy src\cairo-ps.h ..\build\include\cairo
  copy src\cairo-script.h ..\build\include\cairo
  copy src\cairo-svg.h ..\build\include\cairo
  copy src\cairo-win32.h ..\build\include\cairo
  copy cairo-version.h ..\build\include\cairo
  copy src\release\cairo.lib ..\build\lib
  copy src\release\cairo-static.lib ..\build\lib
  copy src\release\cairo.dll ..\build\bin
exit /b
