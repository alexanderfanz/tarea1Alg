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

int main()
{
	//test_patriciantrie();
	
	bool sieve[1000000];
	
	for (int i = 0; i < 1000000; i++)
		sieve[i] = true;
	
	int j = 0;		
	for (int i = 2; i < 500000; i++){
		if (sieve[i]) {
			printf("%d %d\n", i, j + 1);
			if (++j == 1206) {
				printf("%d\n", i);
				break;
			}
			int k = i * 2;
			
			while (k < 1000000) {
				sieve[k] = false;
				k += i;
			}
		}
	}
	
	return 0;
}