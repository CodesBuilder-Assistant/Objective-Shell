# I hate the warning message.
cpp=g++ -O2 -std=c++11 -w
cc=gcc -O2 -w
cc11=gcc -O2 -std=c11 -w
main:
	@$(cc11) src/main.cpp -o build/main.
	# Build tools.
	@$(cc11) tools/linecount.cpp 
	@$(cc) tools/rename.c