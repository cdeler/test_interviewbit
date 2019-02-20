//
// Created by user on 2/20/19.
//

#include <stdlib.h>

static int _compare(const void *a, const void *b)
	{
	return *(int *) a - *(int *) b;
	}

#define MEDIAN(_x, _y) ((_x) + ((_y) - (_x)) / 2)

static int lower_bound_seek(const int *A, int lb, int ub, const int val)
	{
	int mediana;

	while (lb <= ub)
		{
		mediana = MEDIAN(lb, ub);

		if (A[mediana] <= val)
			{
			lb = mediana + 1;
			}
		else
			{
			ub = mediana - 1;
			}
		}

	return lb;
	}

static int upper_bound_seek(const int *A, int lb, int ub, const int val)
	{
	int mediana;

	while (lb <= ub)
		{
		mediana = MEDIAN(lb, ub);

		if (A[mediana] >= val)
			{
			ub = mediana - 1;
			}
		else
			{
			lb = mediana + 1;
			}
		}

	return lb;
	}

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int nTriang(int *A, int n1)
	{
	int64_t sum;
	int i, j, k;

	int result = 0;

	qsort(A, n1, sizeof(int), _compare);

	for (i = 0; i < n1 - 2; ++i)
		{
		for (j = i + 1; j < n1 - 1; ++j)
			{
			sum = A[i] + A[j];

			// looking for a in A[j + 1; n1) , where a < sum
			// i.e. if I insert sum into A, it will be at right of all a

			k = lower_bound_seek(A, j+1, n1 - 1, sum - 1);
			if (k <= n1 && A[k-1] < sum)
				{
				result += (k - 1) - j;
				}

			}

		}


	return result % 1000000007;
	}
