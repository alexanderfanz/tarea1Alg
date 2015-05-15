#include "nodept.h"

Node_PT::Node_PT(){
	suffix_link = 0;
	pos = -1;
}

Node_PT::~Node_PT(){
	if (!suffix_link)
		delete suffix_link;
}

Node_PT* Node_PT::get_suffix_link() {
	return suffix_link;
}

void Node_PT::set_suffix_link(Node_PT* sl) {
	suffix_link = sl;
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

int Node_PT::get_pos() {
	return pos;
}

void Node_PT::set_pos(int p) {
	pos = p;
}

int Node_PT::get_number_of_children() {
	return children.size();
}