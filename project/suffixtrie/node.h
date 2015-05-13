#ifndef NODE_H_
#define NODE_H_

#include <map>

using namespace std;

struct R_Value;

class Node {
	
	private:
		map<char, R_Value> children;
		Node* suffix_link;
		int pos;
		
		friend class Suffix_Trie; // delete this
		
	public:
		Node();
		~Node();
		Node* get_suffix_link();
		void set_suffix_link(Node* sl);
		bool is_c(char c, R_Value& result);
		R_Value insert_c(char c);
		int get_pos();
		void set_pos(int p);
};

struct R_Value {
	Node* node;
};

#endif