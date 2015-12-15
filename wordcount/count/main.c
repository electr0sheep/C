#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100
#define IN_FILE "test.txt"

void process(char, int*, int*, int*, int*);

int main(int argc, const char *argv[]){
	char str[MAX_SIZE];
	int sentences = 0;
	int words = 0;
	int lines = 0;
	int startword = 0;

	printf("Enter a string less than 100 characters:\n");
	scanf("%[^\t\n]s", str);
	printf("You entered: %s\n", str);

	int x = 0;
	while (str[x] != '\0'){
		x++;
		process(str[x], &sentences, &words, &lines, &startword);
	}

	printf("The number of words was: %d\n", words);
	printf("The number of sentences was: %d\n", sentences);
	printf("The number of lines was: %d\n", lines);

	return 0;
}

// This function wouldn't work. I confirmed that the memory addresses
// were correct, but even still, dereferencing them did not change the
// value of the integer they pointed to! Oh well.

void process(char init, int *sentences, int *words, int *lines, int *startword){
	if ((init > 65 && init < 90) || (init > 97 && init < 122)){
		*startword = 1;
	}
	if ((init == ' ' || init == '\0') && *startword == 1){
		*words += 1;
		*startword = 0;
	}
	if (init == '.' || init == ',' || init == '?' || init == '!'){
		*sentences += 1;
	}
	if (init == '\n'){
		*lines += 1;
	}
}
