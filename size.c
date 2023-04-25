#include "main.h"

/**
<<<<<<< HEAD
 * size - the size to cast the arguments is calculated
 * @formt: Formatted string  to print the arguments
 * @x: List of arguments to be printed.
 *
 * Return: Size
*/
int size(const char *formt, int *x)
{
	int curr_x = *x + 1;
	int size = 0;

	if (formt[curr_x] == 'l')
		size = S_LONG;
	else if (formt[curr_x] == 'h')
		size = S_SHORT;

	if (size == 0)
		*x = curr_x - 1;
	else
		*x = curr_x;

	return (size);
}
=======
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

>>>>>>> 544e8e663ee275ea50b6ede730a386beded26b4e
