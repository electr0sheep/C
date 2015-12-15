#include <stdio.h>

#define UPPER_BOUND 100
#define LOWER_BOUND 1
#define STEP 1

double square(double);

int main(int argc, const char * argv[]){

	// variables
	double sumOfSquares = 0;
	double squareOfSums = 0;
	int x;

	// compute sums
	for (x = LOWER_BOUND; x <= UPPER_BOUND; x++){
		sumOfSquares += square(x);
		squareOfSums += x;
	}

	// square the sum of the integers from 1 to 100
	squareOfSums = square(squareOfSums);

	// print the result
	printf("The difference between the sum of squares and square of sums is: %10.0f\n", sumOfSquares - squareOfSums);

	return 0;
}

double square(double num){
	return num * num;
}
