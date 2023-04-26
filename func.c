#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - character is printed
 * @t: List a of arguments
 * @buff: print will be handled by buff array
 * @f: active flags are calculated
 * @w: specifier for width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Printed number of chars
 */
int print_char(va_list t, char buff[],
	int f, int w, int p, int s)
{
	char c = va_arg(t, int);

	return (handle_write_char(c, buff, f, w, p, s));
}
/************************* PRINT A STRING *************************/
/**
 * print_string -  it Prints a string
 * @t: List a of arguments
 * @buff: print will be handled by buff array
 * @f: active flags calculated
 * @w: get width.
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Printed number of chars
 */
int print_string(va_list t, char buff[],
	int f, int w, int p, int s)
{
	int len = 0, i;
	char *str = va_arg(t, char *);

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 7)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (p >= 0 && p < len)
		len = p;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - it Prints a percent sign
 * @t: List of arguments
 * @buff: print will be handled by buff array
 * @f: active flags are calculated
 * @w: get width.
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Prints number of chars
 */
int print_percent(va_list t, char buff[],
	int f, int w, int p, int s)
{
	UNUSED(t);
	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Prints int
 * @t: List of arguments
 * @buff: print to be handled by buff array
 * @f: active flags are calculated
 * @w: get width.
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Prints number of chars
 */
int print_int(va_list t, char buff[],
	int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(t, long int);
	unsigned long int num;

	n = convert_size_number(n, s);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buff, f, w, p, s));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - unsigned number is printed
 * @t: List of arguments
 * @buff: print will be handled by buff array
 * @f:  active flags are calculated
 * @w: get width.
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Prints number of chars
 */
int print_binary(va_list t, char buff[],
	int f, int w, int p, int s)
{
	unsigned int x, y, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	x = va_arg(t, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	a[0] = x / y;
	for (i = 1; i < 32; i++)
	{
		y /= 2;
		a[i] = (x / y) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
