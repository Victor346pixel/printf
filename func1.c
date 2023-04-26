#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - unsigned number is printed
 * @types: List  of arguments
 * @buff: print to be handled by buff
 * @f:  active flags are calculated
 * @w: get width
 * @p: specifier for precision
 * @s: Specifier for size
 * Return: Printed number of chars
 */
int print_unsigned(va_list types, char buff[],
	int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, f, w, p, s));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - usigned number is printed in octal notation
 * @types: List of arguments
 * @buff: print to be handled by buff array
 * @f:  active flags are caculated
 * @w: get width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: Printed number of chars
 */
int print_octal(va_list types, char buff[],
	int f, int w, int p, int s)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, f, w, p, s));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - usigned number in hexadecimal notation is printed
 * @types: List of arguments
 * @buff: print to be handled by buff array
 * @f: active flags are calculated
 * @w: get width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: printed number of chars
 */
int print_hexadecimal(va_list types, char buff[],
	int f, int w, int p, int s)
{
	return (print_hexa(types, "0123456789abcdef", buff,
		f, 'x', w, p, s));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - unsigned number in upper hexadecimal is printed
 * @types: List of arguments
 * @buff: print to be handled by buff array
 * @f: active flags are calculated
 * @w:  width
 * @p: specifier for precision
 * @s: specifier for size
 * Return: printed number of chars
 */
int print_hexa_upper(va_list types, char buff[],
	int f, int w, int p, int s)
{
	return (print_hexa(types, "0123456789ABCDEF", buff,
		f, 'X', w, p, s));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - hexadecimal number is printed in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buff: print to be handled by buf array
 * @f:  active flags are calculated
 * @f_ch: active flags are calculated
 * @w:  width
 * @p: specifier for precision
 * @s: specifier for size
 * @s: specifier for size
 * Return: printed number for chars
 */
int print_hexa(va_list types, char map_to[], char buff[],
	int f, char f_ch, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		buff[i--] = f_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, f, w, p, s));
}
