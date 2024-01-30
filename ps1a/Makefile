CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lboost_unit_test_framework
# Your .hpp files
DEPS = FibLFSR.hpp
# Your compiled .o files
OBJECTS = FibLFSR.o
# The name of your program
PROGRAM = PhotoMagic

.PHONY: all clean lint

all: $(PROGRAM)

FibLFSR.o: FibLFSR.hpp FibLFSR.cpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o *.a $(PROGRAM)

lint:
	cpplint *.cpp *.hpp

PhotoMagic.a: FibLFSR.o
	ar rcs PhotoMagic.a FibLFSR.o PhotoMagic.o