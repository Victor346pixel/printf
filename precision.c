#include "main.h"

/**
<<<<<<< HEAD
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
=======
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
>>>>>>> 544e8e663ee275ea50b6ede730a386beded26b4e
			break;
		}
		else
			break;
	}

<<<<<<< HEAD
	*x = curr_x - 1;

	return (precision);
}
=======
	*i = c - 1;

	return (pr);

>>>>>>> 544e8e663ee275ea50b6ede730a386beded26b4e
