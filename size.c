#include "main.h"

/**
 * size - Calculates the size t
 * @frmt: Formats 
 * @i: List of arguments
 *
 * Return: Precision.
 */
int size(const char *frmt, int *i)
{
	int c = *i + 1;
	int s = 0;

	if (frmt[c] == 'l')
		s = S_LONG;
	else if (frmt[c] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = c - 1;
	else
		*i = c

	return (s);
}

