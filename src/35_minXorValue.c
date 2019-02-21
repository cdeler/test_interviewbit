//
// Created by sergei_krotov on 2/21/19.
//


#include <stdlib.h>

static int _compare(const void *a, const void *b)
	{
	return *(int *) a - *(int *) b;
	}

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int findMinXor(int *A, int n1)
	{
	int i, val, min_val;

	if (n1 == 1)
		{
		return A[0];
		}

	qsort(A, n1, sizeof(int), _compare);

	min_val = A[0] ^ A[1];
	for (i = 2; i < n1; ++i)
		{
		val = A[i] ^ A[i - 1];

		if (val < min_val)
			{
			min_val = val;
			}
		}

	return min_val;
	}
