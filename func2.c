#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - value of a pointer variable is created
 * @t: List a of arguments
 * @buff: print to be handled by buff array
 * @f: active flags are calculated
 * @w: width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Printed number of chars
 */
int print_pointer(va_list t, char buff[],
	int f, int w, int p, int s)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(t, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(p);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f & F_PLUS)
		extra_c = '+', length++;
	else if (f& F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buff[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buff, ind, length,
		w, f, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa
 * @t: List of arguments
 * @buff: print to be handled by buff array
 * @f: active flags are calculated
 * @w:  width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Printed number of chars
 */
int print_non_printable(va_list t, char buff[],
	int f, int w, int p, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(t, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverses a string
 * @t: List of arguments
 * @buff: print to be handled by buff array
 * @f:  active flags are calculated
 * @w:  width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Printed number of chars
 */

int print_reverse(va_list t, char buff[],
	int f, int w, int p, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(t, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @t: Lista of arguments
 * @buff: Buffer array to handle print
 * @f:  Calculates active flags
 * @w:  width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list t, char buff[],
	int f, int w, int p, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(t, char *);
	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
