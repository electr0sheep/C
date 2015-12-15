#include <stdio.h>

#define UPPER_BOUND 10
#define LOWER_BOUND 0
#define STEP 1

int factorial(int);

int main(int argc, const char * argv[]){
	// Print the table header
	printf(" ____________________________________________________\n");
	printf("|   Original Number    |     Factorial of Number     |\n");
	printf("|______________________|_____________________________|\n");

	// Print the body of the table
	// Must declare 'x' outside of loop
	int x;
	for (x = LOWER_BOUND; x <= UPPER_BOUND; x+= STEP){
		printf("|          %2d          |        %10d           |\n", x, factorial(x));
	}

	//Print the table footer
	printf("|____________________________________________________|\n");
	return 0;
}

int factorial(int num){
	if (num == 1 || num == 0){
		return 1;
	}
	else if (num > 1){
		return num * factorial (num - 1);
	}
	else
	// C does not support exception handling. As such, I simply decided to
	//   return -1 in the event that a negative integer is passed to this function
		return -1;
}
