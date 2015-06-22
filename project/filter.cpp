#include <stdio.h>

FILE* output;
char filename[] = "data0.in";
int cont;


void print(char c) {
	
	if (cont++ == 2000000){
		cont = 0;
		filename[4]++;
		fclose(output);
		output = fopen(filename, "wt");	
	}
	
	fprintf(output, "%c", c);
	
}


int main(){
	
	char c;
	output = fopen(filename, "wt");
	cont = 0;
	bool flag = false;
	
	while (scanf("%c", &c) != EOF) {
		if (c >= 'a' && c <= 'z') {
			print(c);
			flag = false;
		}
		else if (c >= 'A' && c <= 'Z') {
			flag = false;
			print(c - 'A' + 'a');
		}
		else if (c == ' ') {
			print(c);
			flag = true;
		}
		else if (!flag) {
			print(' ');
			flag = true;
		}
			
	}
	fclose (output);
	return 0;
}