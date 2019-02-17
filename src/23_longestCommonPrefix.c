//
// Created by user on 2/17/19.
//

#include <stddef.h>
#include <string.h>
#include <malloc.h>

#define BUFFER_SIZE (4096)

/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 *
 * @Output string. Make sure the string ends with null character
 */
char *longestCommonPrefix(char **A, int n1)
	{
	static char buffer[BUFFER_SIZE];
	char c;
	char *result;
	size_t result_len;
	size_t i, j;

	const size_t N = (size_t) n1;
	memset(buffer, 0, BUFFER_SIZE);

	for (j = 0;; ++j)
		{
		c = A[0][j];

		if (c == '\0')
			{
			goto outside;
			}

		for (i = 0; i < N; ++i)
			{
			if (A[i][j] == 0 || A[i][j] != c)
				{
				goto outside;
				}
			}

			buffer[j] = c;
		}

outside:
	result_len = strlen(buffer);
	result = malloc(result_len + 1);

	memmove(result, buffer, result_len);
	result[result_len] = 0;


	return result;
	}
