//
// Created by user on 2/18/19.
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
	int res = power("20");
	assert_int_equal(res, 0);

	res = power("2");
	assert_int_equal(res, 1);

	res = power("1");
	assert_int_equal(res, 0);

	res = power("147573952589676412928");
	assert_int_equal(res, 1);
	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);

	return _cmocka_run_group_tests("test_25", tests, testsCount, NULL, NULL);
	}