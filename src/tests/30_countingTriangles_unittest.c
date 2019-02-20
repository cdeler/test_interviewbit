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
	int *arr;
	int res;

	arr = (int[]) {1, 1, 1, 2, 2,};
	res = nTriang(arr, 5);
	assert_int_equal(res, 4);

	arr = (int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,};
	res = nTriang(arr, 10);
	assert_int_equal(res, 50);


	arr = (int[]) {1, 11, 12,};
	res = nTriang(arr, 3);
	assert_int_equal(res, 0);

	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);

	return _cmocka_run_group_tests("30_countingTriangles_unittest", tests, testsCount, NULL, NULL);
	}
