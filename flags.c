#include "main.h"

/**
 * flags - active flags are calculated
 * @formt: Formatted string to print the arguments
 * @n: takes a parameter.
 * Return: Flags:
 */
int flags(const char *formt, int n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, curr_n;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_n = *n + 1; formt[curr_n] != '\0'; curr_n++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (formt[curr_n] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}

	*n = curr_n - 1;

	return (flags);
}
