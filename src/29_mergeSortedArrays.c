//
// Created by sergei_krotov on 2/20/19.
//

#include <malloc.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 *
 * @Return Returns a array of size n1 + n2 with A and B merged.
 */
int *merge(int *A, int n1, int *B, int n2)
	{
	int i, j, k;
	int *result = malloc((n1 + n2) * sizeof(int));

	i = j = 0;

	while (i < n1 && j < n2)
		{
		if (A[i] < B[j])
			{
			result[i + j] = A[i];
			++i;
			}
		else
			{
			result[i + j] = B[j];
			++j;
			}
		}

	if (i == n1)
		{
		while (j < n2)
			{
			result[i + j] = B[j];
			++j;
			}
		}
	else if (j == n2)
		{
		while (i < n1)
			{
			result[i + j] = A[i];
			++i;
			}
		}

	return result;
	}
