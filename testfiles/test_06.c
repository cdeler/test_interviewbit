//
// Created by user on 2/10/19.
//
#include <stdlib.h>
#include <stdbool.h>

#include "test.h"

// https://www.interviewbit.com/problems/next-permutation/

static void __attribute__((always_inline))
xor_swap(int *arr, int i, int j)
	{
	arr[i] ^= arr[j];
	arr[j] ^= arr[i];
	arr[i] ^= arr[j];
	}

static void _reverse(int *array, int arrSize)
	{
	int i;

	for (i = 0; i < arrSize / 2; ++i)
		{
		xor_swap(array, i, arrSize - 1 - i);
		}
	}

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Void. Just modifies the args passed by reference
 */
void nextPermutation(int *A, int n1)
	{
	int i, j;
	bool swapped = false;

	for (i = n1 - 1; (i > 0) && !swapped; --i)
		{
		if (A[i - 1] < A[i])
			{
			// swap and sort the ending

			for (j = n1 - 1; j >= i; --j)
				{
				if (A[i - 1] < A[j])
					{
					xor_swap(A, i - 1, j);

					swapped = true;

					if (i < n1 - 1)
						{
						_reverse(A + i, n1 - i);
						}

					break;
					}
				}
			}
		}

	if (!swapped)
		{
		_reverse(A, n1);
		}
	}
