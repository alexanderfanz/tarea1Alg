
CC=g++
CFLAGS=-c -Wall

all: project
	
project: main.o suffixtrie.o nodeST.o patriciantrie.o nodePT.o automata.o tfunct.o
	$(CC) main.o suffixtrie.o nodeST.o patriciantrie.o nodePT.o automata.o tfunct.o -o project1
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
suffixtrie.o: suffixtrie/suffixtrie.cpp suffixtrie/suffixtrie.h nodeST.o
	$(CC) $(CFLAGS) suffixtrie/suffixtrie.cpp
	
nodeST.o: suffixtrie/node.cpp suffixtrie/node.h
	$(CC) $(CFLAGS) suffixtrie/node.cpp -o nodeST.o
	
patriciantrie.o: patriciantrie/patriciantrie.cpp patriciantrie/patriciantrie.h nodePT.o
	$(CC) $(CFLAGS) patriciantrie/patriciantrie.cpp
	
nodePT.o: patriciantrie/nodept.cpp patriciantrie/nodept.h
	$(CC) $(CFLAGS) patriciantrie/nodept.cpp -o nodePT.o
	
automata.o: automata/automata.cpp automata/automata.h tfunct.o 
	$(CC) $(CFLAGS) automata/automata.cpp -o automata.o
	
tfunct.o: automata/transitionfunct.cpp automata/transitionfunct.h 
	$(CC) $(CFLAGS) automata/transitionfunct.cpp -o tfunct.o

filter: filter.cpp
	$(CC) filter.cpp -o filter
 
extractquery: extractquery.cpp
	$(CC) extractquery.cpp -o extractquery

clean:
	rm *o project1 filter
	
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