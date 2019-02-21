//
// Created by sergei_krotov on 2/21/19.
//

/**
 * @input A : Integer
 *
 * @Output Integer
 */
int numSetBits(unsigned int A)
	{
	int result = 0;

	while (A)
		{
		A &= A - 1;
		++result;
		}

	return result;
	}
