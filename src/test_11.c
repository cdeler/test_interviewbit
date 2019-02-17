//
// Created by user on 2/10/19.
//
#include <math.h>
#include <stdlib.h>

static const int power_of_5[] = {
		5, 25, 125, 625, 3125,
		15625, 78125, 390625, 1953125, 9765625,
		48828125, 244140625, 1220703125,
};
static const int power_of_5_size = sizeof(power_of_5) / sizeof(int);

/**
 * @input A : Integer
 *
 * @Output Integer
 */
int trailingZeroes(int A)
	{
	int i, t;
	int result = 0;


	for (i = power_of_5_size - 1; i >= 0; --i)
		{
		t = A / power_of_5[i];

		if (t)
			{
			result += t;
			}
		}

	return result;
	}
