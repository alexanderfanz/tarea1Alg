#ifndef NODEPT_H_
#define NODEPT_H_

#include <map>
#include <list>

namespace ns_patrician_trie {
	
using namespace std;

struct R_Value;

class Node_PT {
	
	public:
		map<char, R_Value> children;
		list<int> positions;
		
		
	public:
		Node_PT();
		~Node_PT();
		void add_position(int pos);
		bool is_c(char c, R_Value& result);
		R_Value insert_c(char c);
		int get_number_of_children();
		list<int> get_positions();
};

struct R_Value {
	Node_PT* node;
	char* cad;
};

}
#endif