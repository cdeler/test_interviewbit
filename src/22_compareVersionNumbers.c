//
// Created by user on 2/17/19.
//


#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>

static char *DUMMY = "DUMMY";

static bool _get_version_part(const char *version, char **end, uint64_t *result)
	{
	uint64_t res = 0;
	char *endPtr = NULL;

	if (version == NULL)
		{
		*result = 0;
		*end = DUMMY;
		return false;
		}

	while (*version == '.')
		{
		++version;
		}

	if (*version == '\0')
		{
		*end = NULL;
		*result = 0;
		return false;
		}


	res = strtoull(version, &endPtr, 10);

	assert(errno != ERANGE);
	
	if (errno == EINVAL)
		{
		*result = 0;
		*end = DUMMY;
		return false;
		}

	*result = res;
	*end = endPtr;
	return true;
	}

static bool _is_zero_ending(char *ending)
	{
	bool res;
	uint64_t x = 0;
	char *ptrEnding = ending;

	while (x == 0)
		{
		res = _get_version_part(ptrEnding, &ptrEnding, &x);

		if (!ptrEnding)
			return true;
		}

	return false;
	}

/**
 * @input A : String termination by '\0'
 * @input B : String termination by '\0'
 *
 * @Output Integer
 */
int compareVersion(char *A, char *B)
	{
	uint64_t x = 0xDEADBEEF, y = 0xDEADBEEF;
	bool conv_x, conv_y;
	char *ptrA = A, *ptrB = B;

	for (;;)
		{
		conv_x = _get_version_part(ptrA, &ptrA, &x);
		conv_y = _get_version_part(ptrB, &ptrB, &y);

		if (!conv_x && !conv_y)
			return 0;

		if (!conv_x && conv_y)
			{
			if ((y == 0) && _is_zero_ending(ptrB))
				{
				return 0;
				}
			return -1;
			}

		if (conv_x && !conv_y)
			{
			if ((x == 0) && _is_zero_ending(ptrA))
				{
				return 0;
				}

			return 1;
			}

		if (x < y)
			return -1;

		if (x > y)
			return 1;

		}
	}
