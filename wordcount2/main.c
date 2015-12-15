#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int updateList(char * [], int[], int, char *);
void formatWord(char*);
void clrscrn();
void printTable(char * [], int [], int);
void printHeader();
void printFooter();

int main(int argc, const char * argv []){
	char * words [1000];
	char str [1000];
	int wordCount [1000];
	int y = 0, x = 0;

	// initialize arrays
	for (x = 0; x < 1000; x++){
		words[x] = NULL;
	}

	for (x = 0; x < 1000; x++){
		wordCount[x] = 0;
	}

	x = 0;

	// read from standard input
	if (argc != 2){
		clrscrn();
		printf("Enter a word, followed by the \"Enter\" key as many times as you wish.\n");
		printf("To stop entering words, type a non-letter character only.\n");
		scanf("%s", str);
		formatWord(str);
		while(strcmp(str, "\0") != 0){
			if (updateList(words, wordCount, x, str)){
				x++;
			}
			scanf("%s", str);
			formatWord(str);
		}
	}
	// read from file
	else {
		FILE* file = fopen(argv[1], "r");

		if (file == NULL){
			fprintf(stderr, "The designated file \"%s\" does not exist!\n", argv[1]);
			return -1;
		}

		while(!feof(file)){
			fscanf(file, "%s", str);
			formatWord(str);
			if (updateList(words, wordCount, x, str)){
				x++;
			}
		}
		fclose(file);
	}

	printHeader();
	printTable(words, wordCount, x);
	printFooter();

	return 0;
}

int updateList(char * words[], int wordCount[], int x, char * word){
	int y = 0;

	while (words[y] != NULL){
		if (strcmp(words[y], word) == 0){
			wordCount[y]++;
			return 0;
		}
		y++;
	}

	words[y] = malloc(sizeof(char*));
	strcpy(words[y], word);
	wordCount[y]++;
	return 1;
}

// this function will stop a string at the first character
//  not a letter
// it will also convert uppercase character to lowercase
void formatWord(char * word){
	int x = 0;
	while (word[x] != '\0'){
		// end at the first non letter character
		if ((word[x] < 65) || (word[x]) > 122 || (word[x] > 90 && word[x] < 97)){
			word[x] = '\0';
			return;
		}
		// convert to lowercase
		if (word[x] > 64 && word[x] < 91){
			word[x] += 32;
		}
		x++;
	}
}

void clrscrn(){
	int x;
	for (x = 0; x < 24; x++){
		printf("\n");
	}
}

void printTable(char * words [], int wordCount[], int size){
	int x;
	for (x = 0; x < size; x ++){
		printf("|%20s   |          %3d          |\n", words[x], wordCount[x]);
	}
}

void printHeader(){
	printf(" _______________________________________________\n");
	printf("|          Word         |      Occurences       |\n");
	printf("|_______________________|_______________________|\n");
}

void printFooter(){
	printf("|_______________________________________________|\n");
}
