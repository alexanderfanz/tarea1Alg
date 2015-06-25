#include <stdio.h>
#include <time.h>
#include <list>
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


clock_t begin;
clock_t end;
	
	
void run_experiment_suffix(FILE *out_res, char *data, list<char*> *queries){
	
	begin = clock();
	Suffix_Trie *st = new Suffix_Trie(data);
	end = clock();
	fprintf(out_res, "%.3f,", double(end - begin) / (CLOCKS_PER_SEC / double(1)));
}

void run_experiment_automata(){
	
}


void run_experiment_patrician(){
	
}

void run_experiment() {
	
	FILE *out_res = fopen("results.csv", "wt");
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
	
	for (int i = 0; i < 1; i++){
		begin = clock();
		input = fopen(filename, "rt");
		fgets(data, MAX_CHARS, input);
		fclose(input);
		
		input = fopen(filename_query, "rt");
		while(fscanf(input, "%s\n", cad) != EOF) {
			cad_tmp = new char(strlen(cad) + 1);
			strcpy(cad_tmp, cad);
			queries->push_back(cad_tmp);	
		}
		fclose(input);
		end = clock();
		printf("reading...  %.3f,", double(end - begin) / (CLOCKS_PER_SEC / double(1)));
		fprintf(out_res, "%s,", filename);
		
		begin = clock();
		run_experiment_suffix(out_res, data, queries);
		end = clock();
		printf("%.3f,", double(end - begin) / (CLOCKS_PER_SEC / double(1)));
		
		begin = clock();
		run_experiment_automata();
		end = clock();
		printf("%.3f,", double(end - begin) / (CLOCKS_PER_SEC / double(100)));
		
		begin = clock();
		run_experiment_patrician();
		end = clock();
		printf("%.3f,", double(end - begin) / (CLOCKS_PER_SEC / double(100)));
		
		
	}
	
	
	fclose(out_res);	
}


int main()
{
	//test_suffixtrie();
	
	//test_patriciantrie();
	
	//test_automata();

	run_experiment();
		
	return 0;
}