# Un*x
cpp=g++ -O2 -std=c++11 -w -masm=intel -finput-charset=utf-8
cc=gcc -O2 -std=c11 -w -masm=intel -finput-charset=utf-8
asm=nasm -f elf

# Windows
cpp_win=cl -GR /w
cc_win=cl -GR /w
asm_win=ml /coff /nologo /W 0

# Platform:Linux
# Processor Architecture:amd64(x64)
build_linux_amd64:
	$(cpp) src/main.cpp -o build/linux_amd64/main

	# Tool:srcstat
	$(cpp) src/tools/srcstat/srcstat.cpp -o build/linux_amd64/srcstat
	# Tool:tree
	$(cc) src/tools/tree/tree.c -o build/linux_amd64/tree
	# Tool:rename
	$(cc) src/tools/rename/rename.c -o build/linux_amd64/rename
	# Tool:cpuinfo
	$(cc) src/tools/cpuinfo/cpu.c

# Platform:Windows
# Processor Architecture:i386(x86)
build_win32:
	$(cpp_win) src/main.cpp /Fe "objshell.exe"
configure_environment_deb:
	sudo apt install gcc
	sudo apt install g++
configure_environment_yum:
	sudo yum install gcc
	sudo yum install g++
configure_environment_pacman:
	sudo pacman -Sf gcc
	sudo pacman -Sf g++