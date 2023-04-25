#include "main.h"

/**
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
