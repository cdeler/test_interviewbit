//
// Created by user on 2/16/19.
//
#include <stdint.h>
#include <assert.h>
#include <limits.h>

#define IS_ODD(_x) ((_x)&1)

/**
 * @input x : Integer
 * @input n : Integer
 * @input d : Integer
 *
 * @Output Integer
 */
int powmod(int x, int n, int d)
	{
	int64_t result, accum;

	assert (n >= 0);

	while (x < 0)
		{
		x += d;
		}

	if (x % d == 0)
		{
		return 0;
		}

	result = 1;
	accum = x % d;

	while (n)
		{
		if (IS_ODD(n))
			{
			result = (result * accum) % d;
			}

		accum = (accum * accum) % d;
		n /= 2;
		}

	assert(result <= INT_MAX);
	assert(result >= INT_MIN);

	return (int) result;
	}
