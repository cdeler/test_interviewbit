//
// Created by user on 2/16/19.
//
#include <assert.h>
#include <stdint.h>

#define MIN(_x, _y) (((_x) < (_y)) ? (_x) : (_y))
/**
 * @input A : Integer
 *
 * @Output Integer
 */
int Sqrt(int A)
	{
	int64_t lb, ub, median;

	if (A == 0)
		{
		return 0;
		}
	if (A <= 3)
		{
		return 1;
		}

	ub = A;
	lb = 1;

	while (lb <= ub)
		{
		assert(lb * lb <= A);
		assert(ub * ub >= A);

		median = (lb + ub) / 2;

		if (median == lb)
			{
			// i.e. ub = lb + 1
			return (int)median;
			}
		if (median * median > A)
			{
			ub = median;
			}
		else if (median * median < A)
			{
			lb = median;
			}
		else
			{
			return (int) median;
			}
		}

	return (int)MIN(lb, ub);
	}
