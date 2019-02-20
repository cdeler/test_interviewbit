//
// Created by sergei_krotov on 2/20/19.
//

#include <memory.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int removeDuplicates(int *A, int n1)
	{
	int i, j, saved_point, tail_in_process;
	int result = n1;

	tail_in_process = 0;
	saved_point = 0;
	j = 0;
	for (i = 1; i < n1; ++i)
		{
		if (A[i] != A[saved_point])
			{
			++j;
			A[j] = A[i];

			result -= (i - (saved_point + 1));
			tail_in_process = 0;
			saved_point = i;
			}
		else if (i != saved_point)
			{
			tail_in_process = 1;
			}
		}

	if (tail_in_process)
		{
		result -= (i - (saved_point + 1));
		}

	return result;
	}
