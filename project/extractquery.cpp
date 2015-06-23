#include <stdio.h>

int main() {
	
	char cad[200];
	char filenamein[] = "data0.in";
	char filenameout[] = "query0.in";
	FILE *input, *output;
	int k;
	bool flag;
	
	for (int i = 0; i < 5; i++) {
		
		k = 0;
		flag = true;
		
		input = fopen(filenamein, "rt");
		output = fopen(filenameout, "wt");
		
		while (flag && fscanf(input, "%s", cad) != EOF) {
			
			k = 9; 
			fprintf(output, "%s\n", cad);
			
			while (k--)
				if (fscanf(input, "%s", cad) == EOF) {
					flag = false;
					break;
				}
		}
		
		fclose(input);
		fclose(output);
		
		filenamein[4]++;
		filenameout[5]++;
	}
	return 0;
}