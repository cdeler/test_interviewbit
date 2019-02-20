//
// Created by sergei_krotov on 2/20/19.
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
	int *arr, *arr_exp;
	int res;

	arr = (int[]) {1, 1, 2, 0xDEADBEEF};
	arr_exp = (int[]) {1, 2};
	res = removeDuplicates(arr, 3);
	assert_int_equal(res, 2);
	assert_memory_equal(arr, arr_exp, res);


	arr = (int[]) {1, 1, 1, 1, 1, 1, 0xDEADBEEF};
	arr_exp = (int[]) {1, };
	res = removeDuplicates(arr, 6);
	assert_int_equal(res, 1);
	assert_memory_equal(arr, arr_exp, res);


	arr = (int[]) {0, 0, 0, 1, 1, 1, 0xDEADBEEF};
	arr_exp = (int[]) {0, 1, };
	res = removeDuplicates(arr, 6);
	assert_int_equal(res, 2);
	assert_memory_equal(arr, arr_exp, res);

	arr = (int[]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	arr_exp = (int[]) {0, 1, 2, 3};
	res = removeDuplicates(arr, 71);
	assert_int_equal(res, 4);
	assert_memory_equal(arr, arr_exp, res);

	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);

	return _cmocka_run_group_tests("test_27", tests, testsCount, NULL, NULL);
	}