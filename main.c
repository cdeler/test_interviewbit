#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);

static void print_str_arr(const char **arr, int len);

int main()
	{
	int A[] = {-1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4,};
	int ASize = sizeof(A) / sizeof(int);
	int resLen = -1;

	int *res = searchRange(A, ASize, 4, &resLen);
	print_arr(res, resLen);

	free(res);

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


