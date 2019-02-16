#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);
static void print_str_arr(const char **arr, int len);

int main()
	{
	int A = 5;

	// 4; 4 * 10 + 3;  43 * 10 + 2; 432 * 10 + 1

	printf("Sqrt(%d) = %d\n", A, Sqrt(A));

	return 0;
	}

static void print_str_arr(const char **arr, int len)
	{
	int i;
	printf("[");

	for (i = 0; i < len; ++i)
		{
		printf("%s", arr[i]);
		if (i != len - 1) printf(", ");
		}

	printf("]\n");
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


