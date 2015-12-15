#include <stdio.h>
#include <stdlib.h>

double f2c(double);
void print_table(int, int, int);

#define MIN 0
#define MAX 300
#define STEP 10

/*	main: prints a table mapping temperatures in degrees Fahrenheit to
	their Celsius equivalents */
int main(int argc, const char * argv[]){

	if (argc == 1){
		print_table(MIN, MAX, STEP);
	} else if (argc == 2 && atoi(argv[1]) != 0){
		int num = atoi(argv[1]);
		printf("%3d\t%6.2f\n", num, f2c(num));
	} else if (argc == 3 && (atoi(argv[1]) | atoi(argv[2])) != 0){
		int min, max;
		if (atoi(argv[1]) > atoi(argv[2])){
			min = atoi(argv[2]);
			max = atoi(argv[1]);
			print_table(min, max, STEP);
		} else {
			min = atoi(argv[1]);
			max = atoi(argv[2]);
			print_table(min, max, STEP);
		}
	} else if (argc == 4 && (atoi(argv[1]) | atoi(argv[2]) | atoi(argv[3])) != 0){
		int min, max, step = atoi(argv[3]);
		if (step < 0){
			step *= -1;
			printf("Step value cannot be less than 0\n");
			printf("Converted step to %d\n", step);
		}
		if (atoi(argv[1]) > atoi(argv[2])){
			min = atoi(argv[2]);
			max = atoi(argv[1]);
			print_table(min, max, step);
		} else {
			min = atoi(argv[1]);
			max = atoi(argv[2]);
			print_table(min, max, step);
		}
	} else {
		printf("ERROR: cannot process input\n");
	}

	return 0;
}

/*	f2c: converts the given Fahrenheit temperature to its Celsius
	equivalent */
double f2c(double fahr){
	return (5.0 / 9.0) * (fahr - 32);
}

/*	print_table prints a table blah blah
	blah */
void print_table(int min, int max, int step){
	int x;
	for (x = min; x <= max; x += step){
		printf("%3d\t%6.2f\n", x, f2c(x));
	}
}
