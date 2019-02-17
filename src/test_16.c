//
// Created by user on 2/15/19.
//

#include <stdbool.h>

/**
 * @input A : Integer
 *
 * @Output Integer
 */
int isPalindrome(int A)
	{
	int x, y, digit;
	if (A < 0) return false;
	if (A < 10) return true;

	x = 0;
	y = A;

	while (y > 0)
		{
		digit = y % 10;
		x *= 10;
		x += digit;

		y /= 10;
		}

	return x == A;
	}