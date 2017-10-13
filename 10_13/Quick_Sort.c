#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ElementType int


void quick_process(ElementType * A, int p, int q)
{
	if (p >= q) return;
	int index = p;
	ElementType* i = A + p;
	ElementType key = *(A + p);
	ElementType* sentinel = A + q;
	ElementType temp;
	while (i++ != sentinel)
	{
		if (*i <= key)
		{
			temp = *i;
			*i = *(A + ++index);
			*(A + index) = temp;
		}
	}
	*(A + p) = *(A + index);
	*(A + index) = key;
	quick_process(A, p, index - 1);
	quick_process(A, index + 1, q);
}


void quick_sort(ElementType * A, int N)
{
	quick_process(A, 0, N-1);
}


int main(int argc, char const *argv[])
{
	clock_t start, finish;
	int N = 10;
	// Set a large N
	srand(time(NULL));
	// Set a random seed
	int a[N];
	for (int i=0;i<N;i++)
	{
		a[i] = rand() % 1000000 + 1;
	}
	for (int i=0;i<N;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	// Initialize a random array
	start = clock();
	quick_sort(a, N);
	// Quick Sort
	// Order: small -> large
	finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	// Get the total time of sorting
	for (int i=0;i<N;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	// Print out the result
	printf( "%f seconds\n", duration);
	// Print out the time of sorting
	return 0;
}
