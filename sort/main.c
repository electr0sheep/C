#include <stdio.h>

#define N 20

/* function prototypes */

void selection_sort(int *, int);
int maximum(int *, int);
int minimum(int *, int);
double average(int *, int);
void print_all(int[], int);

/* main */

int main(int argc, const char *argv[]){
	int xs[N];
	int i, max, min;
	double avg;

	/* read in N integers from stdin */
	for (i = 0; i < N; i++){
		scanf("%d", &xs[i]);
	}

	/* print out the original array */
	printf("original array\n");
	print_all(xs, N);

	selection_sort(xs, N);
	printf("sorted array\n");
	print_all(xs, N);

	max = maximum(xs, N);
	min = minimum(xs, N);
	avg = average(xs, N);

	printf("max = %3d\tmin = %3d\tavg = %3.2f\n", max, min, avg);

	return 0;
}

void selection_sort(int * xs, int sz){
	int partition, search, currentVal, minVal, minIndex;

	for (partition = 0; partition < sz - 1; partition++){
		minVal = xs[partition];
		minIndex = partition;
		for (search = partition + 1; search < sz; search++){
			currentVal = xs[search];
			if (currentVal < minVal){
				minIndex = search;
				minVal = currentVal;
			}
		}
		xs[minIndex] = xs[partition];
		xs[partition] = minVal;
	}
}

// function assumes an unsorted array
int maximum(int * xs, int sz){
	int x;
	int max = 0;
	for (x = 0; x < sz; x++){
		if (xs[x] > max)
			max = xs[x];
	}
	return max;
}

// function assumes an unsorted array
// also assumes an array of at least two members
int minimum(int * xs, int sz){
	int x;
	int min = xs[0];
	for( x = 1; x < sz; x++){
		if (xs[x] < min)
			min = xs[x];
	}
	return min;
}

double average(int * xs, int sz){
	int x;
	double avg = 0;
	for (x = 0; x < sz; x++){
		avg += xs[x];
	}
	avg /= sz;
	return avg;
}

void print_all(int xs[], int sz){
	int i;

	for (i = 0; i < sz; i++){
		printf("%d ", xs[i]);
	}
	printf("\n");
}
