#include "main.h"
/**
 * print_handle - Prints a
 * @format: Formats
 * @l: List 
 * @txt: index.
 * @buff: Buff
 * @f: flags
 * @w: width.
 * @pr: Precisio
 * @s : Size 
 * Return: 1 or 2;
 */
int print_handle(const char *format, int *txt, va_list list, char buff[],
	int f, int w, int pr, int s)
{
	int i,len = 0, chars_printed = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(l, buff, f, w, pr, s));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*txt] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*txt - 1] == ' ')
			len += write(1, " ", 1);
		else if (w)
		{
			--(*);
			while (fmt[*txt] != ' ' && fmt[*txt] != '%')
				--(*txt);
			if (fmt[*txt] == ' ')
				--(*txt);
			return (1);
		}
		len += write(1, &fmt[*txt], 1);
		return (len);
	}
	return (printed_chars);
}



