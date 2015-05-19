#ifndef PATRICIANTRIE_H_
#define PATRICIANTRIE_H_

#include "nodept.h"
#include <string.h>
#include <stdio.h>

using namespace ns_patrician_trie;

class Patrician_Trie {

	public:
		Patrician_Trie();
		void insert_string(char* cad, int real_pos);
		void print();
		
	private:
		Node_PT* root;
		int match_pattern(char* pattern, Node_PT* &ptr);
		
		void print(Node_PT* ptr, char* cad, int pos);	
};

#endif