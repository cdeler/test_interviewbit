//
// Created by user on 2/19/19.
//

#include <stdint.h>
#include <malloc.h>
#include <limits.h>


#define GET_VAL(_arr, _i, _N) ( ((_i) < (_N)) ? (_arr)[(_i)] : INT_MAX )
#define IS_ODD(_x) ((_x)&1)

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 *
 * @Output Double
 */
double findMedianSortedArrays(const int *A, int n1, const int *B, int n2)
	{
	int i, j, k, a, b, first_val, second_val;
	const int64_t N = n1 + n2;
	double result;

	i = j = k = 0;
	first_val = second_val = INT_MIN;

	if (n1 == 0)
		{
		if (IS_ODD(n2))
			{
			return (double) B[n2 / 2];
			}
		else
			{
			return ((double) B[n2 / 2] + (double) B[n2 / 2 - 1]) / 2.0;
			}
		}
	else if (n2 == 0)
		{
		if (IS_ODD(n1))
			{
			return (double) A[n1 / 2];
			}
		else
			{
			return ((double) A[n1 / 2] + (double) A[n1 / 2 - 1]) / 2.0;
			}
		}

	while(k <= N / 2)
		{
		a = GET_VAL(A, i, n1);
		b = GET_VAL(B, j, n2);

		++k;

		if (a < b)
			{
			if (k >= N / 2 - 2)
				{
				second_val = first_val;
				first_val = a;
				}
			++i;
			}
		else
			{
			if (k >= N / 2 - 2)
				{
				second_val = first_val;
				first_val = b;
				}
			++j;
			}
		}

	if (IS_ODD(N))
		{
		result = (double) first_val;
		}
	else
		{
		result = ((double) first_val + (double) second_val) / 2.0;
		}

	return result;
	}
