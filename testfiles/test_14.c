//
// Created by user on 2/15/19.
//

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

/**
 * @input A : Integer
 *
 * @Output string array. You need to malloc memory.
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */
char **fizzBuzz(int A, int *len1)
	{
	int i;
	static char buffer[9];
	size_t N;

	char **result = NULL;

	if (A > 0)
		{
		result = calloc(A, sizeof(char *));
		}

	for (i = 1; i <= A; ++i)
		{
		*buffer = 0;

		if (!(i % 3))
			{
			strcat(buffer, "Fizz");
			}

		if (!(i % 5))
			{
			strcat(buffer, "Buzz");
			}

		if ((i % 3) && (i % 5))
			{
			sprintf(buffer, "%d", i);
			}

		N = strlen(buffer);

		result[i - 1] = calloc(N + 1, sizeof(char));
		strncpy(result[i - 1], buffer, N);
		}

	*len1 = A;
	return result;
	}
