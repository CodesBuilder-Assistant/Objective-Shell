# I hate the warning message.
cpp=g++ -O2 -w
cpp11=g++ -O2 -std=c++11 -w
cc=gcc -O2 -w
cc11=gcc -O2 -std=c11 -w
main:
	@$(cpp11) src/main.cpp -o build/main.
	# Build tools.
	@$(cpp11) tools/linecount.cpp 
	@$(cc) tools/rename.c