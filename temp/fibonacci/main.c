#include <stdio.h>

#define UPPER_BOUND 200
#define LOWER_BOUND 2
#define STEP 2

void fibonacci(double[]);

int main(int argc, const char * argv[]){
        // Variables
        double fibonacciNums[UPPER_BOUND];
        double fibonacciSum = 0;
        fibonacci(fibonacciNums);

        // Print the table header
        printf(" _________________________________________________________\n");
        printf("|  Term  |                  Fibonacci Number              |\n");
        printf("|________|________________________________________________|\n");

        // Print the body of the table
        // Must declare 'x' outside of loop

        int x;
for (x = LOWER_BOUND; x <= UPPER_BOUND; x++){
                printf("|  %3d   |%45.0f   |\n", x, fibonacciNums[x - 1]);
        }

        //Print the table footer
        printf("|_________________________________________________________|\n");

        // Calculate sum
        for (x = LOWER_BOUND; x<=UPPER_BOUND; x+= STEP){
                fibonacciSum += fibonacciNums[x-1];
        }

        //Print sum
        printf("The sum of the first 100 even-valued fibonacci numbers is:\n");
        printf("%45.0f\n", fibonacciSum);
        return 0;
}

// This function assumes an array of size UPPER_BOUND
void fibonacci(double array []){
        array[0] = 1;
        array[1] = 2;
        int index;
for (index = 2; index < UPPER_BOUND; index ++){
                array[index] = array[index - 1] + array[index - 2];
        }
}

//I made this function calculate the value of any given term in
//  the fibonacci sequence of numbers. It's not particularly
//  efficient in that the next term in the sequence requires
//  the previous terms to be RECALCULATED, but it seemed simpler
//  to me. However, when I executed the program, I was surprised to
//  find that not only was this method ineffecient, but it was
//  so horrendously ineffecient as to render the program unfinishable,
//  performing an incredible 25,172,538,049 calculations for the 50th
//  term ALONE.

/*
int fibonacci(int term){
        if (term <= 0){
                return -1;
        }
        else if (term == 1){
                calculations ++;
                return 1;
}
        else if (term == 2){
                calculations ++;
                return 2;
        }
        else{
                calculations ++;
                return fibonacci(term - 1) + fibonacci(term - 2);
        }
}
*/
