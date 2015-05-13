#ifndef SUFFIXTRIE_H_
#define SUFFXITRIE_H_

#include "node.h"


class Suffix_Trie {
	
	public:
		Suffix_Trie();
		~Suffix_Trie();
		int get();
		
	private:
	 	Node* root;
};
 
#endif