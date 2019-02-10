//
// Created by user on 2/10/19.
//
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


//
/*
 * x ^ y = A
 * log2 x^y = log2 A
 * y = log2 A / log2 x
 *
 * x in 1..sqrtA
 * y
 */
bool _is_power_internal(int A, int x)
	{
	while (A != 1)
		{
		div_t d = div(A, x);

		if (d.rem != 0)
			{
			return false;
			}
		A = d.quot;
		}

		return true;
	}

/**
 * @input A : Integer
 *
 * @Output Integer
 */
int isPower(int A)
	{
	int i;
	int root;

	if (A <= 1)
		{
		return A;
		}

	root = (int) sqrt(A) + 1;

	for (i = 2; i < root; ++i)
		{
		if (A % i == 0)
			{
			if (_is_power_internal(A, i))
				{
				return true;
				}
			}
		}

	return false;
	}
