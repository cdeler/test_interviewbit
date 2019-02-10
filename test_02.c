//
// Created by user on 2/9/19.
//

#include <stddef.h>
#include <stdlib.h>

#include "test.h"
/**
 * 		S(Act) - S(1..N) = nA - nB
 *
 * 		S(act ** 2) - S(1.. N ** 2) = nA ** 2 - nB ** 2
 *
 * 		3, 1, 2, 5, 3 = S(Act) = 14
 * 		1, 2, 3, 4, 5 = S(1..N) = 15
 *
 * 		9, 1, 4, 25, 9 = S(Act**2) = 48
 * 		1, 4, 9, 16, 25 = S(1..N ** 2) = 55
 * 		S(Act ** 2) - S(1..N ** 2) = nA ** 2 - nB ** 2 = -7
 *
 * 		nA - nB = -1 = X
 * 		(nA**2 - nB**2)/(nA - nB) = nA + nB = -7 / -1 = 7 = Y
 *
 * 		nA - nB = X
 * 		nA + nB = Y
 *
 *
 * 		nA = (X+Y) / 2
 * 		nB = nA - X
 *
 * 		nA = 3
 * 		nB = 4
 */

#define SQR(_x) ((_x) * (_x))

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int *repeatedNumber_copy(const int *A, int n1, int *len1)
	{
	int64_t X, Y, nA, nB, i, sAct, s1N, sAct2, s1N2;
	int *result;

	const int64_t N = (int64_t) n1;

	sAct = s1N = sAct2 = s1N2 = 0;

	for (i = 0; i < N; ++i)
		{
		s1N += (i + 1);
		sAct += A[i];

		sAct2 += SQR((size_t) A[i]);
		s1N2 += SQR(i + 1);
		}

	X = sAct - s1N;
	Y = (sAct2 - s1N2) / X;

	nA = (X + Y) / 2;
	nB = nA - X;

	result = calloc(sizeof(int), 2);
	result[0] = (int) nA;
	result[1] = (int) nB;

	*len1 = 2;

	return result;
	}
