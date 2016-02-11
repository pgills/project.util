echo off
@echo.
@echo *******************************************
@echo * BUILD STARTING   			*
@echo *******************************************
@echo.

call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsMSBuildCmd.bat"

msbuild /verbosity:quiet /fl /property:GenerateLibraryLayout=false /p:NoWarn=0618 tools\buildall.csproj

@echo.
@echo *******************************************
@echo * COPYING BINARIES                        *
@echo *******************************************
@echo.

pushd tools

mkdir ..nuget\lib\uap10.0

mkdir ..\nuget\runtimes\win10-x86\native
mkdir ..\nuget\runtimes\win10-x64\native
mkdir ..\nuget\runtimes\win10-arm\native

copy ..\src\runtimes\win10-x86\native\ProjectUtil.UI.Composition.winmd ..\nuget\lib\uap10.0\

copy ..\src\runtimes\win10-x86\native\ProjectUtil.UI.Composition.dll ..\nuget\runtimes\win10-x86\native
copy ..\src\runtimes\win10-x64\native\ProjectUtil.UI.Composition.dll ..\nuget\runtimes\win10-x64\native
copy ..\src\runtimes\win10-arm\native\ProjectUtil.UI.Composition.dll ..\nuget\runtimes\win10-arm\native

@echo.
@echo *******************************************
@echo * BUILDING NUGET 				*
@echo *******************************************
@echo.

mkdir ..\package
nuget pack ..\nuget\ProjectUtil.UI.Composition.nuspec -o ..\package

@echo.
@echo *******************************************
@echo * DONE 		 			*
@echo *******************************************
@echo.

explorer ..\package

popd