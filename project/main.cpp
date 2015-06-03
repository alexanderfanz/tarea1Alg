#include <stdio.h>
#include "suffixtrie/suffixtrie.h"
#include "patriciantrie/patriciantrie.h"
#include "automata/automata.h"


void test_suffixtrie() {
	char cad[] = {'a', 'a', ' ', 'a', ' ', 'a', '$', '\0'};
	
	Suffix_Trie st(cad);

	st.print();
	
	char cad2[] = {'a', ' ', 'a', '\0'};
	list<int> r = st.find_occ(cad2);
	
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
	pt.insert_string("aabbca", 10);
	pt.insert_string("aaccaa", 6);
	pt.insert_string("aabbcc", 8);
	pt.insert_string("aabb", 7);
	pt.insert_string("aabbcc", 9);
	
	
	pt.print();	
	
	printf("--------------\n");
	
	list<int> r = pt.find_occ("aabbc");
	for (list<int>::iterator it = r.begin(); it != r.end(); it++)
		printf("%d\n", *it);
}

void test_automata() {
	
	Automata *a = new Automata("bcaabc");
	
	
	list<int> r = a->get_occ("abcaabcaabcaabcaa");
	for (list<int>::iterator it = r.begin(); it != r.end(); it++)
		printf("%d\n", *it);
	
	
}

int main()
{
	//test_suffixtrie();
	
	//test_patriciantrie();
	
	test_automata();
	
	return 0;
}