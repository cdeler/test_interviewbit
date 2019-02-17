//
// Created by user on 2/10/19.
//

#include <stdlib.h>
#include <stdint.h>
#include "interviewbit.h"

#define NOT_FOUND (-1)

void set_bit(uint8_t *arr, int num)
	{
	size_t pos = num / 8;
	size_t bit = num % 8;
	arr[pos] ^= (1u << bit);
	}

uint64_t get_bit(const uint8_t *arr, int num)
	{
	size_t pos = num / 8;
	size_t bit = num % 8;

	return (arr[pos] & (1u << bit));
	}

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int repeatedNumber(const int *A, int n1)
	{
	int i;
	int result = NOT_FOUND;
	uint8_t *bitMap = calloc(sizeof(uint8_t), (n1 / 8) + 1);

	for (i = 0; i < n1; ++i)
		{
		if (get_bit(bitMap, A[i]))
			{
			result = A[i];
			break;
			}
		set_bit(bitMap, A[i]);
		}

	free(bitMap);

	return result;
	}
