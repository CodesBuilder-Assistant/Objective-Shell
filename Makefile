help_compatibility:
	@echo [Options]
	@echo help:Show this list
	@echo installer_windows:Build installer on Windows
	@echo clean_cmd:Clear generated files with cmd
	@echo clean_bash:Clear generated files with bash
help_cmd:
	@echo Options:
	@echo help^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ Show this list
	@echo installer_windows^ ^ ^ ^ ^ Build installer on Windows
	@echo clean_cmd^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ Clear generated files with cmd
	@echo clean_bash^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ Clear generated files with bash
help_shell:
	@echo "\033[0mOptions:"
	@echo "\033[34mhelp                  Show this list"
	@echo "\033[94minstaller_windows     Build installer on Windows"
	@echo "\033[97mclean_cmd             Clean generated files with cmd"
	@echo "\033[92mclean_bash            Clean generated files with bash"
installer_windows:
	@cl /Zc:wchar_t  /O2 src\installer\windows\console\installer.c /I include /Fe"build\installer\objshellinst"
	@cl /Zc:wchar_t /GR /O2 src\installer\windows\graphical\installer.cpp /I include /Fe"build\installer\ObjectiveShell_Installer"
	@del installer.obj
	@echo Done.
clean_cmd:
	@rmdir /s /q build
	@mkdir build
	@cd build
	@mkdir installer
	@mkdir bootmedia
	@mkdir docs
	@echo Done.
clean_bash:
	@rm -rf build
	@mkdir build
	@cd build
	@mkdir installer
	@mkdir bootmedia
	@mkdir docs
	@echo 'Done.'
install_windows:
	build\installer\ObjectiveShell_Installer.exe