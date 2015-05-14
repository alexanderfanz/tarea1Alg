#include <stdio.h>
#include "suffixtrie/suffixtrie.h"

int main()
{
	char cad[] = {'a', 'b', 'a', 'a', 'b', 'a', '$', '\0'};
	
	Suffix_Trie st(cad);

	st.print();
	
	char cad2[] = {'a', 'b', 'a', '\0'};
	list<int> r = st.find_occ("a");
	
	printf("%s\n%s\n", cad, cad2);
	r.sort();
	for (list<int>::iterator it = r.begin(); it != r.end(); it++)
		printf("%d\n", *it);
	return 0;
}