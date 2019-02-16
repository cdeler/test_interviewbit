#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);

static void print_str_arr(const char **arr, int len);

int main()
	{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, };
	int ASize = sizeof(A) / sizeof(int);

	int insertIdx = searchInsert(A, ASize, 152);
	printf("insertIdx is %d\n", insertIdx);

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


