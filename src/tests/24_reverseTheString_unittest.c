//
// Created by user on 2/17/19.
//

//
// Created by user on 2/17/19.
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
	static char *data[1][2] =
			{
					{"the sky is blue", "blue is sky the"},
			};
	static const size_t data_size = sizeof(data) / sizeof(data[0]);

	size_t i;
	char *act, *exp;

	for (i = 0; i < data_size; ++i)
		{
		act = strdup(data[i][0]);
		exp = data[i][1];

		reverseWords(act);

		assert_string_equal(act, exp);

		free(act);
		}

	}

int main(int argc, char **argv)
	{

	const struct CMUnitTest tests[] =
			{
					cmocka_unit_test(_test01_smoke),
			};
	const size_t testsCount = sizeof(tests) / sizeof(struct CMUnitTest);


	return _cmocka_run_group_tests("test_24", tests, testsCount, NULL, NULL);
	}