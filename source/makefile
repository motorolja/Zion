#
# Makefile for Zion
#

CCC	= g++ -std=c++11

all: test_item

test_item: test_item.cpp item.o
	$(CCC) -o test_item test_item.cpp item.o

item.o:	item.cpp
	$(CCC) -c item.cpp

clean:
	rm -rf *.o
