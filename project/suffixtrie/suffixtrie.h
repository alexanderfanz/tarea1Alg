#ifndef SUFFIXTRIE_H_
#define SUFFXITRIE_H_

#include "node.h"
#include <cstring>

#include <stdio.h>

class Suffix_Trie {
	
	public:
		Suffix_Trie();
		Suffix_Trie(char* cad);
		~Suffix_Trie();
		void print();
				
	private:
	 	Node* root;
		 
		 void print(Node* ptr, char* cad, int pos);
};
 
#endif