CXX=clang++
CXXFLAGS=-std=c++11 -Wall

all: cmbn
clean:
	rm cmbn

cmbn: cmbn.cpp
