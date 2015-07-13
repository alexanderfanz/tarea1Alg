#include "nodest2.h"

using namespace ns_suffix2;

Node_ST2::Node_ST2(){
	position = -1;
}

Node_ST2::~Node_ST2(){

	for (map<char, R_Value>::iterator it = children.begin(); it != children.end(); it++){
		delete it->second.node;
	}
}

void Node_ST2::set_position(int pos) {
	position = pos;
}

bool Node_ST2::is_c(char c, R_Value& result) {
	
	map<char, R_Value>::iterator it = children.find(c); 
	
	if (it != children.end()) 
		result = it->second;
	return it != children.end();
}

R_Value Node_ST2::insert_c(char c) {
	
	map<char, R_Value>::iterator it = children.find(c); 
	
	if (it != children.end()) 
		return it->second;
	R_Value rvalue;
	rvalue.node = new Node_ST2();
	
	
	children.insert(pair<char, R_Value>(c, rvalue));
	return rvalue;
}


int Node_ST2::get_number_of_children() {
	return children.size();
}

int Node_ST2::get_position() {
	return position;
}