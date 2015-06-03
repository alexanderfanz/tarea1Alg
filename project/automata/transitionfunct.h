#ifndef TRANSITIONFUNCT_H_
#define TRANSITIONFUNCT_H_

#include <string.h>

class TransitionFunction {
	
	public:
		TransitionFunction(char* cad);
		~TransitionFunction();
		int get_next_state(int current_state, char symbol);
		
	private:
		int **f;
		int m; // lenght of the pattern
};
#endif