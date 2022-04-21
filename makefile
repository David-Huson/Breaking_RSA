SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++11 -g
RM=rm -rf

.PHONY: clean

# Target rules
main: main.o utils.o 
	$(CXX) -o $@ $^

# General compilation rules of .o files
main.o: main.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c $<

utils.o: utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c $<

# a test with the original assignment nu
big_mod_test: main
	echo -e "79437491597\n65537\n70502051373\n" | ./main

test: main
	echo -e "620585113\n65537\n604230712\n" | ./main

clean:
	$(RM) *.o main test *.gc* *.dSYM
