CC := mpicc
CXX := mpicxx
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2

.PHONY: all clean

all: hello hello_cpp

hello: hello.c
	$(CC) $(CFLAGS) $< -o $@

hello_cpp: hello_cpp.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) hello hello_cpp
