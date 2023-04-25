#include "main.h"

/**
 * width- gets width for
 * @fmt: Formats
 * @i: List of arguments 
 * @list: list 
 *
 * Return: width.
 */
int width(const char *fmt, int *i, va_list list)
{
	int c;
	int w = 0;

	for (c *i + 1; fmt[c] != '\0'; c++)
	{
		if (digit(fmt[c]))
		{
			w *= 10;
			w += fmt[c] - '0';
		}
		else if (fmt[c] == '*')
		{
			c++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (w);
}

