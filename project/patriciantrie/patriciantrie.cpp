#include "patriciantrie.h"

Patrician_Trie::Patrician_Trie() {
	root = new Node_PT();
}

void Patrician_Trie::insert_string(char* cad, int real_pos) {
	Node_PT* ptr;
	
	int pos = match_pattern(cad, ptr);
	int len = strlen(cad);
	
	
	if (pos < len) {
		
		map<char, R_Value>::iterator it = ptr->children.find(cad[pos]);
		
		if (it == ptr->children.end()) {
			R_Value rvalue;
			rvalue.node = new Node_PT();
			rvalue.cad = new char[len - pos];
			
			for (int i = 0; i < len - pos - 1; i++)
				rvalue.cad[i] = cad[pos + i + 1];
			rvalue.cad[len - pos - 1] = '\0';
			
			ptr->children.insert(pair<char, R_Value>(cad[pos], rvalue));
			ptr = rvalue.node;
		}
		else {
			
			pos++;
			
			int i = 0;
			bool flag = true;
			
			while (cad[pos] != '\0' && it->second.cad[i] != '\0' && flag) {
				flag = cad[pos++] == it->second.cad[i++]; 
			}
			
			
			if (flag) {
				
				char* new_cad = new char[i + 1];
				
				for (int j = 0; j < i; j++)
					new_cad[j] = it->second.cad[j];
				new_cad[i] = '\0';
				
				Node_PT* new_node = new Node_PT();
				R_Value rvalue;
				rvalue.node = it->second.node;
				int len_rvalue_cad = strlen(it->second.cad) - i;
				rvalue.cad = new char[len_rvalue_cad];
				
				for (int j = 0; it->second.cad[i + j + 1] != '\0'; j++)
					rvalue.cad[j] = it->second.cad[i + j + 1];
				rvalue.cad[len_rvalue_cad] = '\0';
				
				new_node->children.insert(pair<char, R_Value>(it->second.cad[i], rvalue));
				
				delete it->second.cad;
				it->second.cad = new_cad;
				it->second.node = new_node;
				ptr = new_node; 
			}
			else {
				
				i--;
				
				char* new_cad = new char[i + 1];
				
				for (int j = 0; j < i; j++)
					new_cad[j] = it->second.cad[j];
				new_cad[i] = '\0';
				
				Node_PT* new_node = new Node_PT();
				R_Value rvalue;
				rvalue.node = it->second.node;
				int len_rvalue_cad = strlen(it->second.cad) - i;
				rvalue.cad = new char[len_rvalue_cad];
				
				for (int j = 0; it->second.cad[i + j + 1] != '\0'; j++)
					rvalue.cad[j] = it->second.cad[i + j + 1];
				rvalue.cad[len_rvalue_cad] = '\0';
				
				new_node->children.insert(pair<char, R_Value>(it->second.cad[i], rvalue));
				
				delete it->second.cad;
				it->second.cad = new_cad;
				it->second.node = new_node;
				
				pos--;
				R_Value rvalue2;
				rvalue2.cad = new char[len - pos];
				for (int j = 0; j < len - pos - 1; j++)
					rvalue2.cad[j] = cad[pos + j + 1];
				rvalue2.cad[len - pos - 1] = '\0';
				ptr = rvalue2.node = new Node_PT();
				
				new_node->children.insert(pair<char, R_Value>(cad[pos], rvalue2));
			}
		}
	}
	
	ptr->add_position(real_pos);
}

int Patrician_Trie::match_pattern(char* pattern, Node_PT* &ptr) {
	
	ptr = root;
	int pos = 0;
	int len = strlen(pattern);
	
	while (pos < len) {
		map<char, R_Value>::iterator it = ptr->children.find(pattern[pos]);
		
		if (it == ptr->children.end()) // end of the match
			return pos;
			  
		if (strlen(it->second.cad) > len - pos - 1) // the match can't reach the next node
			return pos;	
		
		pos++;
			
		int i = 0;
		bool flag = true;
		
		while (pattern[pos + i] != '\0' && it->second.cad[i] != '\0' && flag) {
			flag = pattern[pos + i] == it->second.cad[i++]; 
		}
		
		if (!flag)
			return pos - 1;
		pos += i; 
		ptr = it->second.node;
	}
	
	return pos;
}

void Patrician_Trie::print()
{
	char* cad = new char[100];
	print(root, cad, 0);
}

void Patrician_Trie::print(Node_PT* ptr, char* cad, int pos)
{
	
		cad[pos] = '\0';
		
		for (list<int>::iterator it = ptr->positions.begin(); it != ptr->positions.end(); it++) {
			printf("%s %d\n", cad, *it);
		}
		
		
		for (map<char, R_Value>::iterator it = ptr->children.begin(); it != ptr->children.end(); it++) {
			cad[pos] = it->first;
			int new_pos = pos + 1;
			for (int i = 0; i < strlen(it->second.cad); i++) 
				cad[new_pos++] = it->second.cad[i];
			print(it->second.node, cad, new_pos);
		}
	
		
}

list<int> Patrician_Trie::find_occ(char* pattern) {
	
	Node_PT* ptr;
	
	int pos = match_pattern(pattern, ptr);
	int len = strlen(pattern);
	
	list<int> result;
		
	if (pos < len) {
		
		map<char, R_Value>::iterator it = ptr->children.find(pattern[pos]);
		
		if (it == ptr->children.end()) {
			return result;
		}
		else {
			
			pos++;
			
			int i = 0;
			bool flag = true;
			
			while (pattern[pos] != '\0' && it->second.cad[i] != '\0' && flag) {
				flag = pattern[pos++] == it->second.cad[i++]; 
			}
			
			
			if (flag) {
				
				ptr = it->second.node;
			}
			else {
				
				return result;
			}
		}
	}
	
	
	stack<Node_PT*>* st = new stack<Node_PT*>();
	
	st->push(ptr);
	
	while (!st->empty()) 
	{
		
		ptr = st->top();
		st->pop();
		list<int> tmp = ptr->get_positions();
		
		result.insert(result.end(), tmp.begin(), tmp.end());
		
		for (map<char, R_Value>::iterator it = ptr->children.begin(); it != ptr->children.end(); it++)
			st->push(it->second.node);
	}
	
	return result;
}

list<int> Patrician_Trie::find_whole_occ(char* pattern) {
	Node_PT* ptr;
	
	if (match_pattern(pattern, ptr) < strlen(pattern))
	{
		list<int> r;
		return r;
	} 
	else 
		return ptr->get_positions();
}