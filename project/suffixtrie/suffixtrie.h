#ifndef SUFFIXTRIE_H_
#define SUFFXITRIE_H_

#include "node.h"
#include <cstring>
#include <list>

#include <stdio.h>

class Suffix_Trie {
	
	public:
		Suffix_Trie();
		Suffix_Trie(char* cad);
		~Suffix_Trie();
		void print();
		list<int> find_occ(char* pattern);
				
	private:
	 	Node* root;
		void compress_trie();
		Node* find_pattern(char* pattern);
		list<int> pos_of_leaves(Node* node);
		 
		void print(Node* ptr, char* cad, int pos);
};
 
#endif