//
// Created by user on 2/10/19.
//

#include <stddef.h>
#include <string.h>

// https://www.interviewbit.com/problems/excel-column-number/

/**
 * @input A : String termination by '\0'
 *
 * @Output Integer
 */
int titleToNumber(char *A)
	{
	int i;
	int result = 0;
	const int N = (int)strlen(A);

	for (i = 0; i < N; ++i)
		{
		int diff = ((A[i] - 'A') + 1);
		result *= 26;
		result += diff;
		}

	return result;
	}
