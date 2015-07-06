#include "suffixtrie.h"
#include <stack>
#include <stdio.h>

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
		if (i % 1 == 0)
			printf("Pos   ----->   %d\n", i);
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
	
	compress_trie();
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
		for (unordered_map<char, R_Value>::iterator it = ptr->children.begin(); it != ptr->children.end(); it++) {
			cad[pos] = it->first;
			int new_pos = pos + 1;
			for (int i = 0; i < strlen(it->second.cad); i++) 
				cad[new_pos++] = it->second.cad[i];
			print(it->second.node, cad, new_pos);
		}
	}
		
}

void Suffix_Trie::compress_trie() {
	
	stack<Node*> st;
	st.push(root);
	
	while (!st.empty()) {
		Node* node = st.top();
		st.pop();
		
		for (unordered_map<char, R_Value>::iterator it = node->children.begin(); it != node->children.end(); it++) {
			
			while (it->second.node->get_number_of_children() == 1) {
				Node* tmp = it->second.node;
				it->second.node = tmp->children.begin()->second.node;
				char* cad = new char[strlen(it->second.cad) + 2];
				strcpy(cad, it->second.cad);
				cad[strlen(it->second.cad)] = tmp->children.begin()->first;
				cad[strlen(it->second.cad) + 1] = '\0';
				delete it->second.cad;
				it->second.cad = cad;
				delete tmp;
			}
			
			st.push(it->second.node);
		} 
	}
}

list<int> Suffix_Trie::find_occ(char* pattern) {
	
	list<int> result;
	
	Node* ptr;
	
	if ((ptr = find_pattern(pattern))) {
		return pos_of_leaves(ptr);
	}
	else {
		return result;	
	}
}

Node* Suffix_Trie::find_pattern(char* pattern) {
	
	Node* ptr = root;
	int pos = 0;
	int len = strlen(pattern);
	
	while (pos < len) {
		unordered_map<char, R_Value>::iterator it = ptr->children.find(pattern[pos++]);
		
		if (it == ptr->children.end())
			return 0;  
		int i = 0;
		bool flag = true;
		
		while (pattern[pos] != '\0' && it->second.cad[i] != '\0' && flag) {
			flag = pattern[pos++] == it->second.cad[i++]; 
		}
		
		if (!flag)
			return 0;
		ptr = it->second.node;
	}
	
	return ptr;
}

list<int> Suffix_Trie::pos_of_leaves(Node* node) {
	
	stack<Node*> st;
	st.push(node);
	
	list<int> result;
	
	Node* ptr;
	
	while (!st.empty()) {
		
		ptr = st.top();
		st.pop();
			
		if (ptr->get_pos() != -1) 
			result.push_back(ptr->get_pos());
			
		for (unordered_map<char, R_Value>::iterator it = ptr->children.begin(); it != ptr->children.end(); it++) {
			st.push(it->second.node);
		}
	}
	
	return result;
}