#include <stdio.h>
#include "suffixtrie/suffixtrie.h"

int main()
{
	char cad[] = {'a', 'b', 'a', 'a', 'b', 'a', '$', '\0'};
	
	Suffix_Trie st(cad);

	st.print();
	
	return 0;
}