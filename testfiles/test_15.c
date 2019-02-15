//
// Created by user on 2/15/19.
//

#include <malloc.h>

#define INITIAL_VALUE (1)

int get_input_count(int **arr, int i, int j)
	{
	if (i == 0 && j == 0) return INITIAL_VALUE;

	if (i == 0) return arr[0][j - 1];

	if (j == 0) return arr[i - 1][0];

	return arr[i - 1][j] + arr[i][j - 1];
	}

/**
 * @input A : Integer
 * @input B : Integer
 *
 * @Output Integer
 */
int uniquePaths(int A, int B)
	{
	int result, i, j;
	if (A == 1) return 1;
	if (B == 1) return 1;

	int **map = calloc(A, sizeof(int *));

	for (i = 0; i < A; ++i)
		{
		map[i] = calloc(B, sizeof(int));
		}


	for (i = 0; i < A; ++i)
		{
		for (j = 0; j < B; ++j)
			{
			map[i][j] = get_input_count(map, i, j);
			}
		}

	result = map[A - 1][B - 1];

	for (i = 0; i < A; ++i)
		{
		free(map[i]);
		}
	free(map);

	return result;
	}
