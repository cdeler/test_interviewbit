//
// Created by sergei_krotov on 02/20/2019.
//

#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>
#include <cmocka.h>
#include <malloc.h>
#include <string.h>

#include "interviewbit.h"


static void
_test01_smoke(void **state __unused)
	{
	int *arr1, *arr2, *res, *exp;

	arr1 = (int[]){1, 5, 8};
	arr2 = (int[]){6, 9};
	exp = (int[]){1, 5, 6, 8, 9};

	res = merge(arr1, 3, arr2, 2);
	assert_memory_equal(res, exp, 3 + 2);

	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);

	return _cmocka_run_group_tests("29_mergeSortedArrays_unittest", tests, testsCount, NULL, NULL);
	}