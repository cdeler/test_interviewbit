#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);

int main()
	{
	int i;
	int **arr = calloc(sizeof(int *), 2);
	arr[0] = calloc(sizeof(int), 3);
	arr[1] = calloc(sizeof(int), 3);

	arr[0][0] = 0;	arr[0][1] = 1;	arr[0][2] = 0;
	arr[1][0] = 1;	arr[1][1] = 1;	arr[1][2] = 1;

	setZeroes(arr, 2, 3);

	for (i = 0; i < 2; ++i)
		{
		print_arr(arr[i], 3);
		}

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

	printf("]\n");
	}


