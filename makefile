# Compiler and compiler flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# Phony target for 'make all'
.PHONY: all
all: library

# Target to build the executable 'library' using object files
library: person.o member.o librarian.o book.o library.o date.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Target to build 'person.o' from its source file
person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'member.o' from its source file
member.o: member.cpp member.h person.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'librarian.o' from its source file
librarian.o: librarian.cpp librarian.h person.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'book.o' from its source file
book.o: book.cpp book.h member.h librarian.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'library.o' from its source file
library.o: library.cpp person.h member.h librarian.h book.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'date.o' from its source file
date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c $<

# Phony target for cleaning up generated files
.PHONY: clean
clean:
	$(RM) *.o    # Remove all object files
	$(RM) library  # Remove the executable 'library'
