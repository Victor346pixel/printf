#include "main.h"

/**
 * precision - Calculates the precision 
 * @frmt: Formats
 * @i: List of arguments
 * @ls: list of arguments.
 *
 * Return: Precision.
 */
int precision(const char *frmt, int *i, va_list ls)
{
	int c = *i + 1;
	int pr = -1;

	if (frmt[c] != '.')
		return (pr);

	pr = 0;

	for (c += 1; frmt[c] != '\0'; c++)
	{
		if (digit(frmt[c]))
		{
			pr *= 10;
			pr += frmt[c] - '0';
		}
		else if (frmt[c] == '*')
		{
			c++;
			pr = va_arg(ls, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (pr);

