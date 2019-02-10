//
// Created by user on 2/10/19.
//

//

#define PLACEHOLDER (-1)
#define NEUTRAL (0)
/**
 * @input A : 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Void. Just modifies the args passed by reference
 */
void setZeroes(int **A, int n11, int n12)
	{
	int i, j, ii;

	for (i = 0; i < n11; ++i)
		{
		for (j = 0; j < n12; ++j)
			{
			if (A[i][j] == NEUTRAL)
				{
				for (ii = 0; ii < n11; ++ii)
					{
					if (A[ii][j] != NEUTRAL)
						A[ii][j] = PLACEHOLDER;
					}

				for (ii = 0; ii < n12; ++ii)
					{
					if (A[i][ii] != NEUTRAL)
						A[i][ii] = PLACEHOLDER;
					}
				}
			}
		}
		for (i = 0; i < n11; ++i)
			for (j = 0; j < n12; ++j)
				if (A[i][j] == PLACEHOLDER)
					A[i][j] = NEUTRAL;

	}
