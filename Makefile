$(cpp)=g++ -O2 -std=c++11
$(cc)=gcc -O2
$(cc11)=gcc -O2 -std=c11
main:
	@echo Objective Shell
	@echo Copyright(C)2019 CodesBuilder
	# Build shell main body.
	@$(cpp) src/main.cpp
	# Build tools.
	
