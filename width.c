#include "main.h"

/**
 * get_width- gets width for
 * @fmt: Formats
 * @i: List of arguments 
 * @list: list 
 *
 * Return: width.
 */
int get_width(const char *fmt, int *i, va_list list)
{
	int curr_i;
	int w = 0;

	for (curr_i =  *i + 1; fmt[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(fmt[curr_i]))
		{
			w *= 10;
			w += fmt[curr_i] - '0';
		}
		else if (fmt[curr_i] == '*')
		{
			curr_i++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (w);
}
