#ifndef SUFFIX2_H_
#define SUFFIX2_H_


#include <string.h>
#include <stdio.h>
#include <stack>
#include <list>
#include "nodest2.h"

namespace ns_suffix2 {



class Suffix2 {

	public:
		Suffix2(char *t);
		void print();
		list<int> find_occ(char* pattern);
		list<int> find_whole_occ(char* pattern);
		
	private:
		Node_ST2* root;
		char* text;
		int text_len;
		int match_pattern(int text_pos, Node_ST2* &ptr);
		int match_pattern(char *pattern, Node_ST2* &ptr);
		void insert_string(int text_pos);
		
		void print(Node_ST2* ptr, char* cad, int pos);	
};

}
#endif