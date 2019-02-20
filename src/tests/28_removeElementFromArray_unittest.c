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

	arr = (int[]){4, 1, 1, 2, 1, 3};
	arr_exp = (int[]){4, 2, 3};
	res = removeElement(arr, 6, 1);
	assert_int_equal(res, 3);
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