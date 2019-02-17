//
// Created by user on 2/17/19.
//

#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <assert.h>

#define BUFFER_SIZE (256)

static void _reverse_word(char *word, int word_size)
	{
	int i;
	for (i = 0; i < word_size / 2; ++i)
		{
		word[i] ^= word[word_size - 1 - i];
		word[word_size - 1 - i] ^= word[i];
		word[i] ^= word[word_size - 1 - i];
		}
	}

/**
 * @input A : String termination by '\0'
 *
 * @Output Void. Just modifies the args passed by reference
 */
void reverseWords(char *A)
	{
	static char word_buffer[BUFFER_SIZE];

	char *result;
	int i, j;

	const size_t N = strlen(A);
	memset(word_buffer, 0, BUFFER_SIZE);

	result = calloc(N + 2, sizeof(char));

	for (i = (int) N - 1, j = 0; i >= 0; --i)
		{
		assert(j < BUFFER_SIZE);
		word_buffer[j++] = A[i];

		if (isspace(A[i]))
			{
			word_buffer[j-1] = '\0';

			_reverse_word(word_buffer, j - 1);

			strcat(result, word_buffer);
			strcat(result, " ");

			memset(word_buffer, 0, j);
			j = 0;
			}
		}

	if (!isspace(*word_buffer))
		{
		++j;
		word_buffer[j] = '\0';

		_reverse_word(word_buffer, j - 1);

		strcat(result, word_buffer);
		strcat(result, " ");

		}

	result[N] = '\0';

	memmove(A, result, N);
	free(result);
	}
