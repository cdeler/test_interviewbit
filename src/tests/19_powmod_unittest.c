//
// Created by user on 2/17/19.
//
#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>
#include <cmocka.h>

#include "interviewbit.h"


static void
_test01_powmod(void **state __unused)
	{
	static const int data[2][4] =
			{
					{0, 0, 1, 0},
					{17, 20, 47, 32},
			};
	static const size_t data_size = sizeof(data) / sizeof(data[0]);

	size_t i;
	int  a, n, m, exp, res;

	for (i = 0; i < data_size; ++i)
		{
		a = data[i][0];
		n = data[i][1];
		m = data[i][2];
		exp = data[i][3];

		res = powmod(a, n, m);

		assert_int_equal(exp, res);
		}
	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_powmod),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);


	return _cmocka_run_group_tests("test_21", tests, testsCount, NULL, NULL);
	}