//
// Created by user on 2/10/19.
//

// https://www.interviewbit.com/problems/set-matrix-zeros/

#include <string.h>
#include <stdlib.h>

#include "interviewbit.h"

#define PLACEHOLDER (-1)
#define NEUTRAL (0)

void zeroRow(int **A, int n11, int n12, int rowNo)
	{
	memset(A[rowNo], NEUTRAL, n12 * sizeof(int));
	}

void zeroColumn(int **A, int n11, int n12, int colNo)
	{
	int i, j;

	for (i = 0; i < n11; ++i)
		{
		A[i][colNo] = NEUTRAL;
		}

	}

/**
 * @input A : 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Void. Just modifies the args passed by reference
 */
void setZeroes(int **A, int n11, int n12)
	{
	int i, j;

	int *rows = calloc(sizeof(int), n11);
	int *cols = calloc(sizeof(int), n12);

	for (i = 0; i < n11; ++i)
		{
		for (j = 0; j < n12; ++j)
			{
			if (A[i][j] == NEUTRAL)
				{
				rows[i] = PLACEHOLDER;
				cols[j] = PLACEHOLDER;
				}
			}
		}

	for (i = 0; i < n11; ++i)
		{
		if (rows[i] == PLACEHOLDER)
			{
			zeroRow(A, n11, n12, i);
			}
		}

	for (j = 0; j < n12; ++j)
		{
		if (cols[j] == PLACEHOLDER)
			{
			zeroColumn(A, n11, n12, j);
			}
		}

	free(rows);
	free(cols);
	}