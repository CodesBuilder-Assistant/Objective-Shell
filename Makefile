# Makefile of Objective Shell project
vc=cl /nologo /Zc:wchar_t /O2 /I include
vc64=$(vc) /favor:blend
vcpp=$(vc) /GR /std:c++17
vcpp64=$(vc64) /GR /std:c++17
cs=csc /nologo /target:winexe
masm=ml /nologo /I include
gcc=gcc /share /O2 -std=c11 -Idir include
gpp=g++ /share /O2 -std=c++17
res=rc
link=link /nologo
installer_gcc:

installer_vc:src\installer\windows\console\installer.c src\installer\windows\graphical\installer.cpp src\installer\windows\graphical\res.rc
	@-nmake cls
	@-taskkill /f /im install.exe
	@-taskkill /f /im Objective_Shell_Installer.exe
	@$(vc) src\installer\windows\console\installer.c /Fe"out\installer\install.exe"
	@$(vcpp) /c src\installer\windows\graphical\installer.cpp /Fe"out\installer\Objective_Shell_Installer.exe"
	@$(res)
	@-del *.obj
installer_vc64:src\installer\windows\console\installer.c src\installer\windows\graphical\installer.cpp
	@-nmake cls
	@-taskkill /f /im Objective_Shell_Installer.exe
	@-taskkill /f /im install.exe
	@$(vc64) src\installer\windows\console\installer.c /Fe"out\installer\install.exe"
	@$(vcpp64) src\installer\windows\graphical\installer.cpp /Fe"out\installer\Objective_Shell_Installer.exe"
	@-del *.obj
install_windows:
	@out\installer\ObjectiveShell_Installer.exe
clean:
	@-rm -rf out
	@-mkdir out
	@-cd out
	@-mkdir bootmedia
	@-mkdir docs
	@-mkdir installer
cls:
	@-rmdir /s /q out
	@-mkdir out
	@-cd out
	@-mkdir bootmedia
	@-mkdir docs
	@-mkdir installer