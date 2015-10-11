CXX=clang++
CXXFLAGS=-std=c++11 -Wall

all: c1b1 c1b2 c2b1 cnbn
clean:
	rm c1b1 c1b2 c2b1 cnbn

c1b1: c1b1.cpp
c1b2: c1b2.cpp
c2b1: c2b1.cpp
cnbn: cnbn.cpp
