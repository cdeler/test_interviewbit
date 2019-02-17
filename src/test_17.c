//
// Created by user on 2/15/19.
//

#if 0
const static int pow_of_10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,};

// 0        1           2           3               2           1       0
// 1234     (123 4)    (12 3) 4     (1 2) 3 4      (21 3) 4   321 4    4321
static int _reverse_internal(int A, int *depth, int *max_depth)
	{
	int result;

	*max_depth += 1;
	*depth += 1;

	int digit = A % 10;
	A /= 10;

	if (A == 0)
		{
		result = digit;
		}
	else
		{
		result = _reverse_internal(A, depth, max_depth);
		result += digit * pow_of_10[*max_depth - *depth];
		}

		*depth -= 1;
		return result;
	}

#endif

#include <stdint.h>
#include <limits.h>

/**
 * @input A : Integer
 *
 * @Output Integer
 */
int reverse(int A)
	{
	int64_t accum = 0;

	while (A)
		{
		accum *= 10;
		accum += A % 10;
		A /= 10;
		}

	if (accum < INT_MIN || accum > INT_MAX)
		{
		return 0;
		}

	return (int)accum;
	}
