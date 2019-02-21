//
// Created by sergei_krotov on 02/21/2019.
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

	arr = (int[]) {0, 2, 5, 7,};
	res = findMinXor(arr, 4);
	assert_int_equal(res, 2);

	arr = (int[]) {0, 4, 7, 9,};
	res = findMinXor(arr, 4);
	assert_int_equal(res, 3);

	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);

	return _cmocka_run_group_tests("35_minXorValue", tests, testsCount, NULL, NULL);
	}