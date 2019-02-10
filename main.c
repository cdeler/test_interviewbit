#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);

int main()
	{
	int arr[] = {251, 844, 767, 778, 658, 337, 10, 252, 632, 262, 707, 506, 701, 475, 410, 696, 631, 903, 516, 149, 344,
	             101, 42, 891, 991};
	const int arrSize = sizeof(arr) / sizeof(int);
	printf("Before:\t");
	print_arr(arr, arrSize);
	printf("\nAfter:\t");

	nextPermutation(arr, arrSize);

	print_arr(arr, arrSize);


	int expected[] = {
			251, 844, 767, 778, 658, 337, 10, 252, 632, 262, 707, 506, 701, 475, 410, 696, 631, 903, 516, 149, 344, 101,
			42, 991, 891,};
	printf("\nExp:\t");

	print_arr(expected, arrSize);
	return 0;
	}

static void print_arr(const int *p1, size_t n1)
	{
	size_t i;
	printf("[");

	for (i = 0; i < n1; ++i)
		{
		if (i != 0) printf(", ");
		printf("%d", p1[i]);
		}

	printf("]");
	}


