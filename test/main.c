#include <stdio.h>

int is_prime(int);

int main(int argc, const char * argv[]){
	printf("%d\n", is_prime(6));
	return 0;
}

int is_prime(int number){
	int test;
	for (test = 2; test <= (number/2); test++){
		if (number % test == 0)
			return 0;
	}
	return 1;
}
