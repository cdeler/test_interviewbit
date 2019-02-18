//
// Created by user on 2/18/19.
//

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_SIZE (10)

typedef struct _longint
{
	uint32_t *data;
	size_t len;
	size_t real_size;
} longint_t;


longint_t *longint_alloc()
	{
	longint_t *result = calloc(1, sizeof(longint_t));

	result->data = calloc(INITIAL_SIZE, sizeof(uint32_t));
	result->len = INITIAL_SIZE;
	result->real_size = 0;

	return result;
	}

void longint_dealloc(volatile longint_t **num)
	{
	free((*num)->data);
	free(*num);

	*num = NULL;
	}

void longint_add_int(longint_t *num, const uint32_t A)
	{
	uint64_t val;
	ssize_t i;
	bool is_overflow;

	val = (uint64_t) num->data[0] + A;

	is_overflow = val > UINT32_MAX;

	if (is_overflow)
		{
		num->data[0] = (uint32_t) (val - UINT32_MAX - 1);
		}
	else
		{
		num->data[0] = (uint32_t) (val);
		}

	for (i = 1; is_overflow && i < num->len; ++i)
		{
		num->real_size = i;
		val = num->data[i];

		++val;

		is_overflow = (val > UINT32_MAX);

		num->data[i] = (uint32_t) (val - UINT32_MAX - 1);
		}
	}

void longint_multiple(longint_t *num, const uint16_t A)
	{
	uint64_t val;
	uint64_t overflow_val;
	ssize_t i;
	bool is_overflow;

	val = (uint64_t) num->data[0] * A;
	is_overflow = val > UINT32_MAX;

	if (is_overflow)
		{
		num->data[0] = (uint32_t) (val - UINT32_MAX - 1);
		overflow_val = val / UINT32_MAX;
		}
	else
		{
		num->data[0] = (uint32_t) (val);
		overflow_val = 0;
		}

	for (i = 1; i < num->len; ++i)
		{
		val = num->data[i] * A + overflow_val;

		is_overflow = (val > UINT32_MAX);

		if (is_overflow)
			{
			num->data[i] = (uint32_t) (val - UINT32_MAX - 1);
			overflow_val = val / UINT32_MAX;
			}
		else
			{
			num->data[i] = (uint32_t) (val);
			overflow_val = 0;
			}
		}
	}

static void longint_print(const longint_t *val)
	{
	ssize_t i;

	for (i = val->len - 1; i >= 0; --i)
		{
		printf("%08llX", val->data[i]);
		if (i != 0)
			{
			printf(" ");
			}
		}

	printf("\n");
	}

int is_power_of_two_or_zero(const uint32_t val)
	{
	return !(val & (val - 1));
	}

/**
 * @input A : String termination by '\0'
 *
 * @Output Integer
 */
int power(char *A)
	{
	size_t i, N;
	uint16_t deg;
	longint_t *val = longint_alloc();

	if (!strcmp("1", A))
		{
		return 0;
		}

	N = strlen(A);

	for (i = 0; i < N; ++i)
		{
		deg = (uint16_t) (A[i] - '0');
		longint_multiple(val, 10);
		longint_add_int(val, deg);
		}

	for (i = 0; i < val->len; ++i)
		{
		if (!is_power_of_two_or_zero(val->data[i]))
			{
			return 0;
			}
		}

	longint_dealloc(&val);

	return 1;
	}
