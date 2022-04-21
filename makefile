SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -g
RM=rm -rf

.PHONY: clean

# ONLY MODIFY AT TODOS

# Target rules
main: main.o utils.o 
	$(CXX) -o $@ $^

# General compilation rules of .o files
main.o: main.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c $<

utils.o: utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c $<

large_numbers_test: main
	echo -e "79437491597\n65537\n70502051373\n" | ./main


clean:
	$(RM) *.o main test *.gc* *.dSYM
