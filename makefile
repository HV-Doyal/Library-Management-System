# Compiler and compiler flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# Phony target for 'make all'
.PHONY: all
all: library

# Target to build the executable 'library' using object files
library: person.o library.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Target to build 'person.o' from its source file
person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'library.o' from its source file
library.o: library.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<

# Phony target for cleaning up generated files
.PHONY : clean
clean:
	$(RM) *.o    # Remove all object files
	$(RM) library  # Remove the executable 'library'
