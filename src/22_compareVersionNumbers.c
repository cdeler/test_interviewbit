//
// Created by user on 2/17/19.
//


#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define BUFFER_SIZE (256)

#define MAX(_a, _b) ( ((_a) < (_b)) ? (_b) : (_a) )
#define SIGN(_x) (((_x) > 0) - ((_x) < 0))

static void _get_span(char *buffer, char **pA)
	{
	size_t len;
	assert(pA && *pA);
	char *A = *pA;

	*buffer = '\0';

	while (*A == '.')
		{
		++A;
		}

	char *end = A;

	while (*end != '.' && *end != '\0') ++end;

	len = end - A;

	assert(len < BUFFER_SIZE);

	memmove(buffer, A, len);
	buffer[len] = '\0';
	*pA = end;
	}

static void _zfill(char *buffer, size_t buffer_size, size_t expected_size)
	{
	size_t diff, i;
	assert(expected_size < BUFFER_SIZE);

	if (buffer_size < expected_size)
		{
		diff = expected_size - buffer_size;

		memmove(buffer + diff, buffer, buffer_size);

		for (i = 0; i < diff; ++i)
			{
			buffer[i] = '0';
			}
		}
	}

/**
 * @input A : String termination by '\0'
 * @input B : String termination by '\0'
 *
 * @Output Integer
 */
int compareVersion(char *A, char *B)
	{
	static char x[BUFFER_SIZE], y[BUFFER_SIZE];
	size_t x_len, y_len, max_len;
	char *ptr;
	int res;

	for (;;)
		{
		*x = *y = 0;
		_get_span(x, &A);
		_get_span(y, &B);

		if (!*x && !*y)
			{
			return 0;
			}

		if (*x && *y)
			{
			x_len = strlen(x);
			y_len = strlen(y);

			max_len = MAX(x_len, y_len);

			_zfill(x, x_len, max_len);
			_zfill(y, y_len, max_len);

			if ((res = strcmp(x, y)) != 0)
				{
				return SIGN(res);
				}
			}

		if (*x && !*y)
			{
			ptr = x;

			while (*ptr)
				{
				if (*ptr != '.' && *ptr != '0')
					{
					return 1;
					}

				++ptr;
				}

			return 0;
			}

		if (!*x && *y)
			{
			ptr = y;

			while (*ptr)
				{
				if (*ptr != '.' && *ptr != '0')
					{
					return -1;
					}

				++ptr;
				}

			return 0;
			}
		}
	}
