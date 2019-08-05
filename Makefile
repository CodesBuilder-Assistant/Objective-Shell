# Makefile of Objective Shell project
vc=cl /nologo /Zc:wchar_t /O2 /I include /std:c++17
vcpp=$(vc) /GR
cs=csc /nologo /target:winexe
masm=ml /nologo /I include
gcc=gcc /share /O2 -std=c11 -Idir include
gpp=g++ /share /O2 -std=c++17
installer_gcc:
installer_vc:src\installer\windows\console\installer.c src\installer\windows\graphical\installer.cpp
	@$(vc) src\installer\windows\console\installer.c /Fe"out\installer\install.exe"
	@$(vcpp) src\installer\windows\graphical\installer.cpp /Fe"out\installer\Objective_Shell_Installer.exe"
	@del installer.obj
install_windows:
	@out\installer\ObjectiveShell_Installer.exe
clean:
	@rm -rf out
	@mkdir out
	@cd out
	@mkdir bootmedia
	@mkdir docs
	@mkdir installer
cls:
	@rmdir /s /q out
	@mkdir out
	@cd out
	@mkdir bootmedia
	@mkdir docs
	@mkdir installer