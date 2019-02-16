//
// Created by user on 2/16/19.
//

#include <stddef.h>
#include <malloc.h>

#define MEDIAN(_x, _y) ((_x) + ((_y) - (_x)) / 2)

static int _bsearch_internal(const int *A, int lb, int ub, const int val)
	{
	int mediana;
	while (lb <= ub)
		{
		mediana = MEDIAN(lb, ub);

		if (A[mediana] > val)
			{
			ub = mediana - 1;
			}
		else if (A[mediana] < val)
			{
			lb = mediana + 1;
			}
		else
			{
			return mediana;
			}
		}

	return lb;
	}

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

#define DOESNT_EXIST (-1)

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int *searchRange(const int *A, int n1, int B, int *len1)
	{
	int idx, lb, ub;
	int *result;

	*len1 = 2;
	result = calloc(2, sizeof(int));

	idx = _bsearch_internal(A, 0, n1 - 1, B);

	if (idx == n1 || (A[idx] != B))
		{
		result[0] = DOESNT_EXIST;
		result[1] = DOESNT_EXIST;
		return result;
		}

	lb = lower_bound_seek(A, 0, idx, B - 1);
	ub = upper_bound_seek(A, 0, n1 - 1, B + 1) - 1;

	result[0] = lb;
	result[1] = ub;

	return result;
	}
