CXX = g++
CXXFLAGS = -std=c++17 -g -O2 

.PHONY: all
all: clean hello
	@echo The hello program has been compiled
	clear
	ls -a 

# implicit rule: create x from x.cpp
.cpp:
	$(CXX) $(CXXFLAGS) $? -o $@

.PHONY: clean
clean:
	$(RM) -r hello *.dSYM

