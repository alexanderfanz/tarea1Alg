#include <stdio.h>
#include "suffixtrie/suffixtrie.h"
#include "patriciantrie/patriciantrie.h"


void test_suffixtrie() {
	char cad[] = {'a', 'b', 'a', 'a', 'b', 'a', '$', '\0'};
	
	Suffix_Trie st(cad);

	st.print();
	
	char cad2[] = {'a', 'b', 'a', '\0'};
	list<int> r = st.find_occ("a");
	
	printf("%s\n%s\n", cad, cad2);
	r.sort();
	for (list<int>::iterator it = r.begin(); it != r.end(); it++)
		printf("%d\n", *it);
}

void test_patriciantrie() {
	
	Patrician_Trie pt;
	
	pt.insert_string("aabbaa", 1);
	pt.insert_string("aabb", 2);
	pt.insert_string("aabbcc", 4);
	pt.insert_string("aaccaa", 6);
	
	pt.print();	
}

int main()
{
	test_patriciantrie();
	
	return 0;
}