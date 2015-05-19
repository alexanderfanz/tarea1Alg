#include "nodept.h"

using namespace ns_patrician_trie;


Node_PT::Node_PT(){
	
}

Node_PT::~Node_PT(){

}

void Node_PT::add_position(int pos) {
	positions.push_back(pos);
}

bool Node_PT::is_c(char c, R_Value& result) {
	
	map<char, R_Value>::iterator it = children.find(c); 
	
	if (it != children.end()) 
		result = it->second;
	return it != children.end();
}

R_Value Node_PT::insert_c(char c) {
	
	map<char, R_Value>::iterator it = children.find(c); 
	
	if (it != children.end()) 
		return it->second;
	R_Value rvalue;
	rvalue.node = new Node_PT();
	rvalue.cad = new char[1];
	rvalue.cad[0] = '\0';
	
	children.insert(pair<char, R_Value>(c, rvalue));
	return rvalue;
}


int Node_PT::get_number_of_children() {
	return children.size();
}