//
// Created by sergei_krotov on 2/21/19.
//
#include <stddef.h>
#include <limits.h>
#include <string.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int singleNumber(const int *A, int n1)
	{
	int bit, i, j, result;
	static size_t set_bits[CHAR_BIT * sizeof(size_t)];
	memset(set_bits, 0, sizeof(set_bits));

	for (i = 0; i < CHAR_BIT * sizeof(int); ++i)
		{
		bit = 1 << i;

		for (j = 0; j < n1; ++j)
			{
			if (A[j] & bit)
				{
				set_bits[i] += 1;
				}
			}
		}

	result = 0;
	for (i = 0; i < CHAR_BIT * sizeof(int); ++i)
		{
		if (set_bits[i] % 3 == 1)
			{
			result |= (1 << i);
			}
		}

	return result;
	}
