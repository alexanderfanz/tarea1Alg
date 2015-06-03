#include "transitionfunct.h"

TransitionFunction::TransitionFunction(char* cad) {
	
	m = strlen(cad);
	
	f = new int*[m + 1];
	
	for (int i = 0; i < m + 1; i++)
	{
		f[i] = new int[256];
		
		for (int j = 0; j < 256; j++) 
			f[i][j] = 0;
	}
	
	for (int q = 0; q < m + 1; q++){
		for (char c = 0; c < 256; c++){
			
		    if (q < m && c == cad[q])
		        f[q][c] = q + 1;
		 	else {
				 
			    int ns, i;  // ns stores the result which is next state
			 
			    // ns finally contains the longest prefix which is also suffix
			    // in "pat[0..state-1]c"
			 
			    // Start from the largest possible value and stop when you find
			    // a prefix which is also suffix
			    for (ns = q; ns > 0; ns--)
			    {
			        if(cad[ns-1] == c)
			        {
			            for(i = 0; i < ns-1; i++)
			            {
			                if (cad[i] != cad[q-ns+1+i])
			                    break;
			            }
			            if (i == ns-1) {
			                f[q][c] = ns;
							break;
						}
			        }
			    }
			}
		}
	}
}

TransitionFunction::~TransitionFunction() {
	for (int i = 0; i < m + 1; i++)
		delete [] f[i];
	
	delete [] f;	
}

int TransitionFunction::get_next_state(int current_state, char symbol) {
	return f[current_state][symbol];
}