//
// Created by sergei_krotov on 2/20/19.
//

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 * @Output Integer
 */
int removeElement(int *A, int n1, int B)
	{
	int result = n1;
	int i, j;

	for (i = 0, j = 0; i < n1; ++i)
		{
		if (A[i] != B)
			{
			A[j++] = A[i];
			}
		else
			{
			--result;
			}
		}

	return result;
	}
