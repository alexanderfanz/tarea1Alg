#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <list>
#include "transitionfunct.h"


class Automata {
	
	public:
		Automata(char* pattern);
		~Automata();
		std::list<int> get_occ(char* text);
		
	private:
		int m;	
		TransitionFunction *tf;
};


#endif
