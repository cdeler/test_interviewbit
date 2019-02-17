//
// Created by user on 2/17/19.
//
#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>
#include <cmocka.h>

#include "interviewbit.h"


static void
_test01_smoke(void **state __unused)
	{
	static char * data[] =
			{
					"444444444444444444444444", "4444444444444444444444444",
					"1", "1.0",
					"0.1", "1.1",
					"1.3", "1.34.2",
					"1.3", "1.3.2",
					"1.2", "1.2",
					"0", "0",
					"2.6", "1.34.6",
			};
	static int expected[] = {-1, 0, -1, -1, -1, 0, 0, 1, };
	const static size_t data_size = (sizeof(data) / sizeof(data[0])) / 2;

	size_t i;
	char *A, *B;
	int res, exp;

	for (i = 0; i < data_size; ++i)
		{
		A = data[2*i];
		B = data[2*i + 1];
		exp = expected[i];

		res = compareVersion(A, B);
		assert_int_equal(exp, res);
		}
	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);


	return _cmocka_run_group_tests("test_22", tests, testsCount, NULL, NULL);
	}