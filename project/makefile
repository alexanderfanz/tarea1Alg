
CC=g++
CFLAGS=-c -Wall

all: project
	
project: main.o suffixtrie.o
	$(CC) main.o suffixtrie.o -o project
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
suffixtrie.o: suffixtrie.cpp suffixtrie.h
	$(CC) $(CFLAGS) suffixtrie.cpp
clean:
	rm *o project
	
#all: hello

#hello: main.o factorial.o hello.o
#    g++ main.o factorial.o hello.o -o hello
#
#main.o: main.cpp
#    g++ -c main.cpp
#
#factorial.o: factorial.cpp
#    g++ -c factorial.cpp
#
#hello.o: hello.cpp
#    g++ -c hello.cpp
#
#clean:
#    rm *o hello