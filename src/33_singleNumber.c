//
// Created by sergei_krotov on 2/21/19.
//

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int singleNumber(const int *A, int n1)
	{
	int i;
	int result = 0;

	for (i = 0; i < n1; ++i)
		{
		result ^= A[i];
		}

	return result;
	}
