#include <stdio.h>
#include <time.h>
#include <list>
#include "suffixtrie/suffixtrie.h"
#include "patriciantrie/patriciantrie.h"
#include "automata/automata.h"
#include "suffixtrie2/suffix2.h"


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


void test_suffix2() {
	char cad[] = "mississippi";
	//char cad[] = "aab";
	
	ns_suffix2::Suffix2 st(cad);

	st.print();
	
	
}


void test2_suffixtrie() {
	Suffix_Trie st("ababababab$");
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


clock_t _begin;
clock_t _end;
	
	
void run_experiment_suffix(FILE *out_res, char *data, list<char*> *queries){
	
	_begin = clock();
	Suffix_Trie *st = new Suffix_Trie(data);
	_end = clock();
	fprintf(out_res, "%.3f,", double(_end - _begin) / (CLOCKS_PER_SEC / double(1)));
	fprintf(out_res, "%.3f,", double(_end - _begin) / (CLOCKS_PER_SEC / double(1)));
	
}

void run_experiment_automata(FILE *out_res, char *data, list<char*> *queries){
	
	int count = 0;
	
	fprintf(out_res, "%.3f,", 0);
	Automata *a;
	_begin = clock();
	
	for (std::list<char*>::iterator it = queries->begin(); it != queries->end(); it++, count++){
		if (count % 1000 == 0) printf("%d\n", count);
		
		 a = new Automata(*it);
	
	
		list<int> r = a->get_occ(data);
		
		delete a;
	}
		
	_end = clock();
	fprintf(out_res, "%.3f,", double(_end - _begin) / (CLOCKS_PER_SEC / double(1)));
	 
}

void run_experiment_suffix2(FILE *out_res, char *data, list<char*> *queries){
	int count = 0;
	
	_begin = clock();
	
	Patrician_Trie *pt = new Patrician_Trie();
	int len = strlen(data);
	int i = 0;
	char cad[1000];
	int cc;
	
	printf("filling the suffix2 ....\n");
	
	for (int i = 0; i < len; i++){
		pt->insert_string(cad + i, i);
		printf("%d\n", i);
	}
	
	_end = clock();
	fprintf(out_res, "%.3f,", double(_end - _begin) / CLOCKS_PER_SEC);
	
	_begin = clock();
	printf("consulting the patrician trie....\n");
	
	for (std::list<char*>::iterator it = queries->begin(); it != queries->end(); it++, count++){
		if (count % 1000 == 0) printf("%d\n", count);
		
		pt->find_occ(*it); 
	}
		
	_end = clock();
	fprintf(out_res, "%.3f\n", double(_end - _begin) / CLOCKS_PER_SEC);
	
	delete pt;
}

void run_experiment_patrician(FILE *out_res, char *data, list<char*> *queries){
	int count = 0;
	
	_begin = clock();
	
	Patrician_Trie *pt = new Patrician_Trie();
	int len = strlen(data);
	int i = 0;
	char cad[1000];
	int cc;
	
	printf("filling the patrician trie....\n");
	while (data[i] == ' ') i++;
	while (i < len){
		cc = 0;
		while (data[i] >= 'a' && data[i] <= 'z') cad[cc++] = data[i++];
		cad[cc] = '\0';
		pt->insert_string(cad, i - cc);
		while (data[i] == ' ') i++;
		
		if (i % 7 == 0) printf("%d\n", i);
	}
	
	_end = clock();
	fprintf(out_res, "%.3f,", double(_end - _begin) / CLOCKS_PER_SEC);
	
	_begin = clock();
	printf("consulting the patrician trie....\n");
	
	for (std::list<char*>::iterator it = queries->begin(); it != queries->end(); it++, count++){
		if (count % 1000 == 0) printf("%d\n", count);
		
		pt->find_occ(*it); 
	}
		
	_end = clock();
	fprintf(out_res, "%.3f\n", double(_end - _begin) / CLOCKS_PER_SEC);
	
	delete pt;
}


void run_experiment() {
	
	FILE *out_res = fopen("./results/results.csv", "wt");
	FILE *input;
	char filename[] = "../books/data/data0.in";
	char filename_query[] = "../books/data/query0.in";
	const int MAX_CHARS = 2000000; 
	char *data = new char[MAX_CHARS + 1];
	std::list<char*> *queries = new list<char*>();
	char cad[1000];
	char *cad_tmp;
	
	fprintf(out_res, "-,SuffixTrie,-,Automata,-,PatricianTrie,-\n");
	fprintf(out_res, "Test No,Build,Consult,Build,Consult,Build,Consult\n");
	
	
	
	for (int i = 0; i < 5; i++){
		_begin = clock();
		input = fopen(filename, "rt");
		fgets(data, MAX_CHARS, input);
		fclose(input);
		
		queries->clear();
		input = fopen(filename_query, "rt");
		while(fscanf(input, "%s\n", cad) != EOF) {
			cad_tmp = new char(strlen(cad) + 1);
			strcpy(cad_tmp, cad);
			queries->push_back(cad_tmp);	
		}
		fclose(input);
		_end = clock();
		printf("reading...  %.3f\n", double(_end - _begin) / (CLOCKS_PER_SEC / double(1)));
		fprintf(out_res, "%s,", filename);
		
		//run_experiment_suffix(out_res, data, queries);
		run_experiment_suffix2(out_res, data, queries);
		
		//run_experiment_automata(out_res, data, queries);
		
		//run_experiment_patrician(out_res, data, queries);
		
		
		filename[18]++;
		filename_query[19]++;
		
	}
	
	
	fclose(out_res);	
}

void testtest(){
	
	_begin = clock();
	for (int i = 0; i < 1000000000; i++){
		
		//if (i % 1000 == 0) printf("%d\n", i/1000);
		int a = 10;
		int b = a * 77;
	}
	_end = clock();
	printf("%.3f,", double(_end - _begin) / (CLOCKS_PER_SEC));
}

int main()
{
	//test_suffixtrie();
	//test2_suffixtrie();
	
	//test_patriciantrie();
	
	//test_automata();

	//run_experiment();
	
	//testtest();
	
	test_suffix2();
	return 0;
}