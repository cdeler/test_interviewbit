#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef TEST_01
const int arr[] = {3, 30, 34, 5, 9};
	const int n1 = sizeof(arr) / sizeof(int);

	char *s = largestNumber(arr, n1);

	printf("%s\n", s);

	free(s);
#endif

#include "interviewbit.h"

static void print_arr(const int *p1, size_t n1);


#define MAX_INT_LEN (11)

static int compare(const void *p1, const void *p2)
	{
	char n1[MAX_INT_LEN * 2] = {0};
	char n2[MAX_INT_LEN * 2] = {0};
	size_t i;

	snprintf(n1, MAX_INT_LEN * 2, "%d%d", *(int *) p1, *(int *) p2);
	snprintf(n2, MAX_INT_LEN * 2, "%d%d", *(int *) p2, *(int *) p1);

	return -strcmp(n1, n2);
	}

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output string. Make sure the string ends with null character
 */
char *largestNumber(const int *A, int n1)
	{
	size_t i, resLen;
	const size_t N = (size_t) n1;
	char buffer[12];
	int *array_copy = malloc(sizeof(int) * N);
	char *result = malloc(MAX_INT_LEN * N + 1);

	*result = '\0';

	for (i = 0; i < N; ++i)
		{
		array_copy[i] = A[i];
		}

	qsort(array_copy, N, sizeof(int), compare);

	if (array_copy[0] == 0)
		{
		sprintf(result, "%d", 0);
		}
	else
		{
		for (i = 0; i < N; ++i)
			{
			snprintf(buffer, 11, "%d", array_copy[i]);
			strcat(result, buffer);
			}

		}

	free(array_copy);

	return result;
	}

