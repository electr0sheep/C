#include <stdio.h>
#include <stdlib.h>

int checkParen(const char*);

int main(int argc, const char * argv[]){
	FILE* file = fopen(argv[1], "r");
	char str[1000];

	while(!feof(file)){
		fscanf(file, "%s", str);
		if (checkParen(str)){
			printf("balanced\n");
		} else {
			printf("not balanced\n");
		}
	}
	fclose(file);

	return 0;
}

int checkParen(const char* string){
	int x = 0;
	int numParen = 0;

	while(string[x] != '\0'){
		//printf("%s\n", &string[x]);
		if (string[x] == '('){
			numParen++;
		} else if (string[x] == ')'){
			numParen--;
		}
		x++;
	}
	if (numParen == 0){
		return 1;
	} else {
		return 0;
	}
}