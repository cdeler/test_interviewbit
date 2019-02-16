//
// Created by user on 2/16/19.
//

int _bsearch_internal(const int *A, int lb, int ub, const int val)
	{
	int mediana;
	while (lb <= ub)
		{
		mediana = lb + (ub - lb) / 2;

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

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 * @Output Integer
 */
int searchInsert(int *A, int n1, int B)
	{
	return _bsearch_internal(A, 0, n1 - 1, B);;
	}
