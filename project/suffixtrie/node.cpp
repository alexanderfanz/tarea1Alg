#include "node.h"

Node::Node(){
	
}

Node::~Node(){
	if (!suffix_link)
		delete suffix_link;
}