
CC=g++
CFLAGS=-c -Wall

all: project
	
project: main.o suffixtrie.o node.o
	$(CC) main.o suffixtrie.o node.o -o project1
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
suffixtrie.o: suffixtrie/suffixtrie.cpp suffixtrie/suffixtrie.h node.o
	$(CC) $(CFLAGS) suffixtrie/suffixtrie.cpp
	
node.o: suffixtrie/node.cpp suffixtrie/node.h
	$(CC) $(CFLAGS) suffixtrie/node.cpp
	
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