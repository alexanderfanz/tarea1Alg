#ifndef NODE_H_
#define NODE_H_

#include <map>

using namespace std;

class Node {
	
	private:
		map<char, Node *> children;
		Node* suffix_link;
		
	public:
		Node();
		~Node();
};

#endif