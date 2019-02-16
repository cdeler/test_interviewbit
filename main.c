#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);
static void print_str_arr(const char **arr, int len);

int main()
	{
	int a = 0, n = 0, m = 1;
	// int a = 71045970, b = 41535484, c = 64735492;

	printf("powmod(%d, %d, %d) = %d\n", a, n, m, powmod(a, n, m));

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


