//
// Created by user on 2/10/19.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "test.h"

void print_intervals(const interval *is, int isSize)
	{
	int i;
	interval *it;
	for (i = 0; i < isSize; ++i)
		{
		it = (interval *) is + i;
		printf("[%d %d] ", it->start, it->end);
		}
	printf("\n");
	}

interval *get_intervals(const int *arr, size_t arrLen)
	{
	int iCount = arr[0];
	int i;
	interval *result = calloc(sizeof(interval), iCount);

	for (i = 0; i < iCount; ++i)
		{
		interval *cur = &result[i];

		cur->start = arr[1 + 2 * i];
		cur->end = arr[1 + 2 * i + 1];
		}

	return result;
	}

static int _compare(const void *i1, const void *i2)
	{
	const interval *interval1 = i1;
	const interval *interval2 = i2;

	if (interval1->start != interval2->start)
		{
		return interval1->start - interval2->start;
		}
	else
		{
		return interval1->end - interval2->end;
		}
	}

int is_overlaping(const interval *i1, const interval *i2)
	{
	assert(i1->start <= i2->start);

	return (i1->end >= i2->start);
	}

static void merge_internal(interval *i1, interval *i2)
	{
	assert(i1->start <= i2->start);

	if (i1->end >= i2->end)
		{
		// i2 inside i1
		return;
		}
	else
		{
		i1->end = i2->end;
		}
	}

/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * len : populate the length of returned array of intervals in len
 */
interval *merge(interval *intervals, int sz, int *len)
	{
	int i;
	qsort(intervals, (size_t) sz, sizeof(interval), _compare);

	i = sz - 1;
	while (i > 0)
		{
		if (is_overlaping(&intervals[i - 1], &intervals[i]))
			{
			merge_internal(&intervals[i - 1], &intervals[i]);

			memmove(intervals + i, intervals + i + 1, sizeof(interval) * (sz - (i + 1)));
			--sz;
			i = sz - 1;
			continue;
			}
		--i;
		}

	*len = sz;
	return intervals;
	}
