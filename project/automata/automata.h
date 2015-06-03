#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <list>

class Automata {
	
	public:
		Automata(char* pattern);
		~Automata();
		std::list<int> get_occ(char* text);
		
	private:
		int m;		
};


#endif
