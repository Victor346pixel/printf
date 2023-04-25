#include "main.h"

/**
 * precision - Calculates the precision for printing
 * @formt: Formatted string  to print the arguments
 * @x:  arguments to be printed.
 * @lst: list of arguments.
 *
 * Return: Precision.
 */
int precision(const char *formt, int *x, va_list lst)
{
	int curr_x = *x + 1;
	int precision = -1;

	if (formt[curr_x] != '.')
		return (precision);

	precision = 0;

	for (curr_x += 1; formt[curr_x] != '\0'; curr_x++)
	{
		if (is_digit(formt[curr_x]))
		{
			precision *= 10;
			precision += formt[curr_x] - '0';
		}
		else if (formt[curr_x] == '*')
		{
			curr_x++;
			precision = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*x = curr_x - 1;

	return (precision);
}
