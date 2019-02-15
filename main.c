#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

static void print_arr(const int *p1, size_t n1);

int main()
	{
	int res = gcd(4, 6);

	printf("Result is %d\n", res);


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


