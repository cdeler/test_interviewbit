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

	arr = (int[]) {1, 2, 4, 3, 3, 2, 2, 3, 1, 1,};
	res = singleNumber(arr, 10);
	assert_int_equal(res, 4);
	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);

	return _cmocka_run_group_tests("34_singleNumber2", tests, testsCount, NULL, NULL);
	}