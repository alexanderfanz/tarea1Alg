#ifndef NODEPT_H_
#define NODEPT_H_

#include <map>

using namespace std;

struct R_Value;

class Node_PT {
	
	private:
		map<char, R_Value> children;
		Node_PT* suffix_link;
		int pos;
		
		friend class Suffix_Trie; // delete this
		
	public:
		Node_PT();
		~Node_PT();
		Node_PT* get_suffix_link();
		void set_suffix_link(Node_PT* sl);
		bool is_c(char c, R_Value& result);
		R_Value insert_c(char c);
		int get_pos();
		void set_pos(int p);
		int get_number_of_children();
};

struct R_Value {
	Node_PT* node;
	char* cad;
};

#endif