CXX = nvcc
CXXFLAGS = -g -O3  -std=c++11

INCLUDES =
LDFLAGS =
LDLIBS =

# clear any suffixes
.SUFFIXES:
# set suffixes
.SUFFIXES: .cpp .cu

all: test
	@echo add programs compiled

# implicit rule: create x from x.cpp
.cpp:
	module load shared; \
	module load gcc9; \
	module load cuda11.2/toolkit; \
	$(CXX) $(CXXFLAGS) $? -o $@

# implicit rule: create x from x.cu
.cu:
	module load shared; \
	module load gcc9; \
	module load cuda11.2/toolkit; \
	$(CXX) $(CXXFLAGS) $? -o $@

.PHONY: clean
clean:
	$(RM) -r test

