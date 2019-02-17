#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

#include "interviewbit.h"

static int __attribute__((always_inline))
_get_coeff(int **arr, size_t i, size_t j)
	{
	if (j > i)
		{
		return 0;
		}
	else
		{
		return arr[i][j];
		}
	}

/**
 * @input A : Integer
 *
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns
 */
int **solve(int A, int *len1, int *len2)
	{
	size_t i, j;
	int **result;
	assert(A >= 1);
	const size_t N = (size_t) A;


	result = calloc(sizeof(int *), N);

	result[0] = calloc(sizeof(int), 1);
	result[0][0] = 1;

	for (i = 1; i < N; ++i)
		{
		result[i] = calloc(sizeof(int), i + 1);

		result[i][0] = 1;

		for (j = 1; j < i + 1; ++j)
			{
			result[i][j] = _get_coeff(result, i - 1, j - 1) + _get_coeff(result, i - 1, j);
			}
		}

	*len1 = A;
	*len2 = A;
	return result;
	}
