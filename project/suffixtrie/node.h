#ifndef NODE_H_
#define NODE_H_

#include <map>

using namespace std;

struct R_Value;

class Node {
	
	public:
		map<char, R_Value> children;
		Node* suffix_link;
		
	public:
		Node();
		~Node();
		Node* get_suffix_link();
		void set_suffix_link(Node* sl);
		bool is_c(char c, R_Value& result);
		R_Value insert_c(char c);
};

struct R_Value {
	Node* node;
};

#endif