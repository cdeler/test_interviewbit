//
// Created by user on 2/15/19.
//

#include <stdlib.h>

#define XOR_SWAP(_x, _y) do {(_x)^=(_y); (_y)^=(_x); (_x)^=(_y);} while(0);
#define IS_EVEN(_x) (!((_x & 1)))

/**
 * @input A : Integer
 * @input B : Integer
 *
 * @Output Integer
 */
int gcd(int A, int B)
	{
	int result = 1;

	while (1)
		{
		if (A == 0) return B * result;
		if (B == 0) return A * result;
		if (A == B) return A * result;

		if (IS_EVEN(A) && IS_EVEN(B))
			{
			result *= 2;
			A /= 2;
			B /= 2;
			continue;
			}

		if (IS_EVEN(A))
			{
			A /= 2;
			continue;
			}

		if (IS_EVEN(B))
			{
			B /= 2;
			continue;
			}

		if (A < B)
			{
			B = (B - A) / 2;
			continue;
			}
		else
			{
			A = (A - B) / 2;
			continue;
			}
		}
	#ifdef RECURSIVE
	if (A == 0) return B;
	if (B == 0) return A;
	if (A == B) return A;

	if (IS_EVEN(A) && IS_EVEN(B)) return 2 * gcd(A / 2, B / 2);

	if (IS_EVEN(A)) return gcd(A / 2, B);

	if (IS_EVEN(B)) return gcd(A, B / 2);

	if (A < B)
		{
		return gcd(A, (B - A) / 2);
		}
	else
		{
		return gcd((A - B) / 2, B);
		}

	#endif
	}
