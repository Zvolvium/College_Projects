# Makefile
# 
# Compiles a C++/OpenMP application. 
#
# $ make 
#
# -g adds debugging information to the executable file

CXX 		= g++
CXXFLAGS	= -std=c++11 -g -O2 -fopenmp


all: hw4
	@echo Examples have been compiled

# implicit rule: build an executable x from x.cu
.cpp:
	$(CXX) $(CXXFLAGS) $< -o $@ 


.PHONY: clean
clean:
	$(RM) -f hw4
