//
// Created by user on 2/10/19.
//
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "interviewbit.h"

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int *plusOne(int *A, int n1, int *len1)
	{
	int *result;
	int i;
	int leadingZeros;
	bool shiftFlag;
	int resultLen;
	const size_t N = (size_t) n1;

	result = calloc(sizeof(int), N + 1);

	memmove(result + 1, A, N * sizeof(int));
	shiftFlag = true;

	for (i = (int) N; shiftFlag; --i)
		{
		result[i] += 1;

		if (result[i] >= 10)
			{
			result[i] %= 10;
			}
		else
			{
			shiftFlag = false;
			}
		}

	leadingZeros = 0;

	for (i = 0; (i < n1 + 1) && (result[i] == 0); ++i) ++leadingZeros;

	resultLen = n1 + 1 - leadingZeros;
	if (leadingZeros > 0)
		{
		memmove(result, result + leadingZeros, ((size_t) resultLen) * sizeof(int));
		}


	*len1 = resultLen;

	return result;
	}
