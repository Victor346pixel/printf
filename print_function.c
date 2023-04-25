#include "main.h"

Void buffer_print(char buff[], int *index_b);

/**
 *_printf -this one of main C output function(printf)
 *@format this parameter formats
 * Return: returns the printed characters
 */
int _printf(const char *format, ...)
{
	int x, pr = 0 ,char_printed = 0;
	int f, w, pr, s,index_b = 0;
	var_list ls;
	char buff[SIZE_B];
	
	if (format == NULL)
		return (-1);

va_start(ls, format);

for (x = 0; format && format[x] != '\0'; x++)
{
if (format [x] != '%')
{
buff[index_b++]= format[x];	
if (index_b == SIZE_B)
	buffer_print(buff ,&index_b);
char_printed++;
}
else
{
buffer_print(buff, &index_b);
f = get_f(format, &x);
w = get_w(format, &x, ls);
p = get_p(format, &x, ls);
s = get_s(format, &x);
++i;
pr = print_h(format, &x, ls, buff, f, w, p, s);

if (pr == -1)
	return (-1);

char_printed += pr;
		}
	}
buffer_print(buff,index_b);

va_end(ls);

return (chars_printed);

}

/**
 * buffer_print -  this function prints what is in the buffer
 * @buff:this is an Arr of chars
 * @index_b: Index at where yu add next character.
 */
void buffer_print(char buff[], int *index_b)
{
	if (*index_b > 0)
		write(1, &buff[0], *index_b);

	*index_b = 0;
}
