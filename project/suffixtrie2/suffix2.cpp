#include "suffix2.h"


using namespace ns_suffix2;


Suffix2::Suffix2(char *t) {
	text = new char[(text_len = strlen(t)) + 1];
	strcpy(text, t);
	root = new Node_ST2();
	
	for (int i = 0; i < text_len; i++){
		printf("inserting:   ");
		int j = i;
		while (j < text_len) printf("%c", text[j++]);
		printf("\n");
		insert_string(i);
		print();
		printf("-----------------------------\n");
		printf("-----------------------------\n");
	}
}

void Suffix2::insert_string(int text_pos) {
	Node_ST2* ptr;
	
	int pos = match_pattern(text_pos, ptr);
	int len = text_len - text_pos;
	
	printf("pos from match   %d\n", pos);
	if (pos < len) {
		
		printf("pos from match   %d\n", pos);
		
		map<char, R_Value>::iterator it = ptr->children.find(text[text_pos + pos]);
		
		if (it == ptr->children.end()) {
			R_Value rvalue;
			rvalue.node = new Node_ST2();
			rvalue.pos = text_pos + pos + 1;
			rvalue.len = text_len - text_pos + pos - 1;
			
			ptr->children.insert(pair<char, R_Value>(text[text_pos + pos], rvalue));
			ptr = rvalue.node;
		}
		else {
			
			pos++;
			
			int i = 0;
			bool flag = true;
			
			while (text_pos + pos < text_len && it->second.pos + i < text_len && flag) {
				flag = text[text_pos + pos++] == text[it->second.pos + i++]; 
			}
			
			printf("*p %d *i %d   %d\n", pos, i, flag);
			if (flag) {
				
				Node_ST2* new_node = new Node_ST2();
				R_Value rvalue;
				rvalue.node = it->second.node;
				rvalue.pos = it->second.pos + it->second.len - i - 1;
				rvalue.len = it->second.len - i - 1;
				
				
				new_node->children.insert(pair<char, R_Value>(text[it->second.pos + i], rvalue));
				
				it->second.len = i;
				it->second.node = new_node;
				ptr = new_node; 
			}
			else {
				
				i--;
				pos--;
				
				//char* new_cad = new char[i + 1];
				
				//for (int j = 0; j < i; j++)
				//	new_cad[j] = it->second.cad[j];
				//new_cad[i] = '\0';
				
				Node_ST2* new_node = new Node_ST2();
				R_Value rvalue;
				rvalue.node = it->second.node;
				//int len_rvalue_cad = strlen(it->second.cad) - i;
				//rvalue.cad = new char[len_rvalue_cad];
				
				rvalue.len = it->second.len - i - 1;
				rvalue.pos = it->second.pos + i + 1;
				
				//for (int j = 0; it->second.cad[i + j + 1] != '\0'; j++)
				//	rvalue.cad[j] = it->second.cad[i + j + 1];
				//rvalue.cad[len_rvalue_cad] = '\0';
				
				new_node->children.insert(pair<char, R_Value>(text[it->second.pos + i], rvalue));
				
				//delete it->second.cad;
				//it->second.cad = new_cad;
				it->second.node = new_node;
				it->second.len = i;
				
				//pos--;
				R_Value rvalue2;
				//rvalue2.cad = new char[len - pos];
				//for (int j = 0; j < len - pos - 1; j++)
					//rvalue2.cad[j] = cad[pos + j + 1];
				//rvalue2.cad[len - pos - 1] = '\0';
				rvalue2.pos = text_pos + pos + 1;
				rvalue2.len = text_len - text_pos - pos - 1; 
				ptr = rvalue2.node = new Node_ST2();
				
				printf("^^^  p %d   l %d   text+pos %d\n", rvalue2.pos, rvalue2.len, text_pos + pos);
				
				new_node->children.insert(pair<char, R_Value>(text[text_pos + pos], rvalue2));
			}
		}
	}
	
	ptr->set_position(text_pos);
}

int Suffix2::match_pattern(int text_pos, Node_ST2* &ptr) {
	
	ptr = root;
	int pos = 0;
	int len = text_len - text_pos;
	
	while (pos < len) {
		map<char, R_Value>::iterator it = ptr->children.find(text[text_pos + pos]);
		
		if (it == ptr->children.end()) // end of the match
			return pos;
			  
		if (it->second.len > len - pos - 1) // the match can't reach the next node
			return pos;	
		
		pos++;
			
		int i = 0;
		bool flag = true;
		
		while (text[text_pos + pos + i] != '\0' && it->second.len > i && flag) {
			flag = text[text_pos + pos + i] == text[it->second.pos + i++]; 
		}
		
		if (!flag)
			return pos - 1;
		pos += i; 
		ptr = it->second.node;
	}
	
	return pos;
}

void Suffix2::print()
{
	char* cad = new char[100];
	print(root, cad, 0);
}

void Suffix2::print(Node_ST2* ptr, char* cad, int pos)
{
	
		if (ptr->get_position() != -1) {
			cad[pos] = '\0';
			printf("----->   %s %d\n", cad, ptr->get_position());
		}
		
		
		
		for (map<char, R_Value>::iterator it = ptr->children.begin(); it != ptr->children.end(); it++) {
			cad[pos] = it->first;
			int new_pos = pos + 1;
			printf("pos %d    len %d    %d\n", it->second.pos, it->second.len, ptr->children.size());
			for (int i = 0; i < it->second.len; i++) 
				cad[new_pos++] = text[it->second.pos + i];
			print(it->second.node, cad, new_pos);
		}
	
	
}

list<int> Suffix2::find_occ(char* pattern) {
	
	Node_ST2* ptr;
	/*
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
	
	
	stack<Node_ST2*>* st = new stack<Node_ST2*>();
	
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
	*/
}

list<int> Suffix2::find_whole_occ(char* pattern) {
	/*
	Node_ST2* ptr;
	
	if (match_pattern(pattern, ptr) < strlen(pattern))
	{
		list<int> r;
		return r;
	} 
	else 
		return ptr->get_positions();
		
		*/
}