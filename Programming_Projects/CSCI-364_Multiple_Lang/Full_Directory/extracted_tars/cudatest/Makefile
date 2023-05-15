# Makefile
# 
# Compiles a CUDA test application. 
#
# $ make 
#
# -g adds debugging information to the executable file

# Nvidia CUDA compiler
CXX 		= nvcc
CXXFLAGS	= -std=c++11 -g -O2

# clear any suffixes
.SUFFIXES:
# set suffixes
.SUFFIXES: .cu


all: cudatest drivertest
	@echo CUDA Test has been compiled

# implicit rule: build an executable x from x.cu
.cu:
	module load shared; \
	module load gcc9; \
	module load cuda11.2/toolkit; \
	$(CXX) $(CXXFLAGS) $< -o $@ 


.PHONY: clean
clean:
	$(RM) -f cudatest drivertest devicecount


