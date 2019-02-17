//
// Created by user on 2/17/19.
//

#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>
#include <cmocka.h>
#include <malloc.h>

#include "interviewbit.h"


static void
_test01_smoke(void **state __unused)
	{
	static const char *data[2][4] =
			{
					{"abcdefgh", "aefghijk", "abcefgh", "a"},
					{"abcd", "abcd", "efgh", ""},
			};
	static const size_t data_size = sizeof(data) / sizeof(data[0]);

	size_t i;
	char *res, **row;

	for (i = 0; i < data_size; ++i)
		{
		row = (char **) data[i];

		res = longestCommonPrefix(row, 3);

		assert_string_equal(row[3], res);

		free(res);
		}
	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);


	return _cmocka_run_group_tests("test_23", tests, testsCount, NULL, NULL);
	}