#include "node.h"

Node::Node(){
	suffix_link = 0;
}

Node::~Node(){
	if (!suffix_link)
		delete suffix_link;
}

Node* Node::get_suffix_link() {
	return suffix_link;
}

void Node::set_suffix_link(Node* sl) {
	suffix_link = sl;
}

bool Node::is_c(char c, R_Value& result) {
	
	map<char, R_Value>::iterator it = children.find(c); 
	
	if (it != children.end()) 
		result = it->second;
	return it != children.end();
}

R_Value Node::insert_c(char c) {
	
	map<char, R_Value>::iterator it = children.find(c); 
	
	if (it != children.end()) 
		return it->second;
	R_Value rvalue;
	rvalue.node = new Node();
	
	children.insert(pair<char, R_Value>(c, rvalue));
	return rvalue;
}

int Node::get_pos() {
	return pos;
}

void Node::set_pos(int p) {
	pos = p;
}