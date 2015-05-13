#include "suffixtrie.h"

Suffix_Trie::Suffix_Trie(){
	root = new Node();
}

Suffix_Trie::Suffix_Trie(char* cad){
	root = new Node();
	
	int len = strlen(cad);
	
	Node* ptr;
	Node* prev_ptr;
	Node* first = root;
	
	for (int i = 0; i < len; i++) {
		
		ptr = first;
		
		first = first->insert_c(cad[i]).node;
		
		prev_ptr = first;
		
		ptr = ptr->get_suffix_link();
		
		while (ptr) {
			Node* tmp = ptr->insert_c(cad[i]).node;
			
			prev_ptr->set_suffix_link(tmp);
			prev_ptr = tmp;
			
			ptr = ptr->get_suffix_link();
		}
		
		prev_ptr->set_suffix_link(root);
	}
	
	int pos = 0;
	while (first) {
		first->set_pos(pos++);
		first = first->get_suffix_link();	
	}
}

Suffix_Trie::~Suffix_Trie(){
	delete root;
}

void Suffix_Trie::print()
{
	char* cad = new char[100];
	print(root, cad, 0);
}

void Suffix_Trie::print(Node* ptr, char* cad, int pos)
{
	if (ptr->children.size() == 0) {
		cad[pos] = '\0';
		printf("%s %d\n", cad, ptr->get_pos());
	}
	else {
		for (map<char, R_Value>::iterator it = ptr->children.begin(); it != ptr->children.end(); it++) {
			cad[pos] = it->first;
			print(it->second.node, cad, pos + 1);
		}
	}
		
}