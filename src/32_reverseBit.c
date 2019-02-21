//
// Created by sergei_krotov on 2/21/19.
//

#include <limits.h>

/**
 * @input A : Integer
 *
 * @Output Integer
 */
unsigned int reverse(unsigned int A)
	{
	int i;
	unsigned int result = A;
	const int N = sizeof(result) * CHAR_BIT;

	for (i = 0; i < N; ++i)
		{
		result <<= 1;
		result |= A & 1;
		A >>= 1;
		}

	return result;
	}
