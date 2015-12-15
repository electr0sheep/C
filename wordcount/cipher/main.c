#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100
#define IN_FILE "test.txt"

char cipher(char);

int main(int argc, const char *argv[]){
	char str[MAX_SIZE];

	printf("Enter a string less than 100 characters:\n");
	scanf("%[^\t\n]s", str);
	printf("You entered: %s\n", str);

	int x = 0;
	while (str[x] != '\0'){
		str[x] = cipher(str[x]);
		x++;
	}

	printf("The ciphered text is:\n%s\n", str);

	return 0;
}

char cipher(char init){
	switch(toupper(init)){
		case 'A':
		return 'E';

		case 'B':
		return 'M';

		case 'C':
		return 'N';

		case 'D':
		return 'V';

		case 'E':
		return 'D';

		case 'F':
		return 'L';

		case 'G':
		return 'W';

		case 'H':
		return 'A';

		case 'I':
		return 'U';

		case 'J':
		return 'C';

		case 'K':
		return 'P';

		case 'L':
		return 'O';

		case 'M':
		return 'K';

		case 'N':
		return 'X';

		case 'O':
		return 'Q';

		case 'P':
		return 'B';

		case 'Q':
		return 'I';

		case 'R':
		return 'Z';

		case 'S':
		return 'J';

		case 'T':
		return 'R';

		case 'U':
		return 'Y';

		case 'V':
		return 'T';

		case 'W':
		return 'G';

		case 'X':
		return 'S';

		case 'Y':
		return 'H';

		case 'Z':
		return 'F';

		default:
		return init;
	}
}