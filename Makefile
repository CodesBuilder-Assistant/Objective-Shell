cpp=g++ -O2 -w
cpp11=g++ -O2 -std=c++11 -w
cc=gcc -O2 -w
cc11=gcc -O2 -std=c11 -w
build_linux_amd64:
	$(cpp11) src/main.cpp -o build/linux_amd64/main
	# Build tools.
	$(cpp11) src/tools/linecount.cpp -o build/linux_amd64/linecount
	$(cc) src/tools/tree.c -o build/linux_amd64/tree
	$(cc) src/tools/rename.c -o build/linux_amd64/rename
build_win32:
	windres src/res.rc -o build/win32/res.res
	$(cpp11) -c src/main.cpp -o build/win32/main.o

	del build/win32/res.res
configure_environment_deb:
	sudo apt install gcc
	sudo apt install g++
configure_environment_yum:
	sudo yum install gcc
	sudo yum install g++
configure_environment_pacman:
	sudo pacman -Sf gcc
	sudo pacman -Sf g++