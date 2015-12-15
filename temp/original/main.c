#include <stdio.h>

#define UPPER_BOUND 300
#define LOWER_BOUND 0
#define STEP 20

double fToC(int);

int main(int argc, const char * argv[]){
	// Print the table header
	printf(" _________________________________________________________________\n");
	printf("|   Temperature in Fahrenheit    |     Temperature in Celsius     |\n");
	printf("|________________________________|________________________________|\n");

	// Print the body of the table
	// Must declare 'x' outside of loop
	int x;
	for (x = LOWER_BOUND; x <= UPPER_BOUND; x+= STEP){
		printf("|              %3d               |             %6.2f             |\n", x, fToC(x));
	}

	//Print the table footer
	printf("|_________________________________________________________________|\n");
	return 0;
}

double fToC(int f){
	return (5.0/9.0) * (f - 32);
}
