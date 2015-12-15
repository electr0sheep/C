#include <stdio.h>

#define UPPER_BOUND 300
#define LOWER_BOUND 0
#define STEP 20

double fToC(int);
double fToK(int);

int main(int argc, const char * argv[]){
	// Print the table header
	printf(" ____________________________________________________________________________\n");
	printf("| Temperature in Fahrenheit | Temperature in Celsius | Temperature in Kelvin |\n");
	printf("|___________________________|________________________|_______________________|\n");

	// Print the body of the table
	// Must declare 'x' outside of loop
	int x;
	for (x = LOWER_BOUND; x <= UPPER_BOUND; x+= STEP){
		printf("|            %3d            |         %6.2f         |         %6.2f        |\n", x, fToC(x), fToK(x));
	}

	//Print the table footer
	printf("|____________________________________________________________________________|\n");
	return 0;
}

double fToC(int f){
	return (5.0/9.0) * (f - 32);
}

// I went ahead and just be the hard-coded celsius to kelvin constant
//   The number you add to celsius to get kelvin won't change until an
//   alternate universe where the known laws of physics no longer apply
double fToK(int f){
	return fToC(f) + 273.15;
}
