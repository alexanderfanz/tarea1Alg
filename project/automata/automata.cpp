#include "automata.h"

Automata::Automata(char* pattern) {
	
	m = strlen(pattern);
	
	tf = new TransitionFunction(pattern);	
}

Automata::~Automata() {
	
	delete tf;	
}

std::list<int> Automata::get_occ(char* text) {
	
	int state = 0;
	int next_state;
	int pos = 0;
	std::list<int> result;
	
	while (text[pos] != '\0') {
		
		if ((state = tf->get_next_state(state, text[pos++])) == m) {
			result.push_back(pos - m);
		}
	} 
	
	return result;
}