#include "main.h"
/**
 * handle_char - thhis function Prints a string
 * @ch: this is the character types.
 * @buff:  array of buffer to handle print
 * @f:  Counts flags that are active.
 * @w : gets the width.
 * @pr:  specifies the precision
 * @s:  spicifies size
 *
 * Return: total number of characters printed
 */
int handle_char(char ch, char buff[],
	int f, int w, int pr, int s)
{ /* character is stored at left and paddind at buffer's right */
	int i = 0;
	char paddind = ' ';

	UNUSED(pr);
	UNUSED(s);

	if (f & F_ZERO)
		paddind = '0';

	buff[i++] = ch;
	buff[i] = '\0';

	if (w > 1)
	{
		buffer[SIZE_B - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buff[SIZE_B - i - 2] = paddind;

		if (f & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[SIZE_B - i - 1], w - 1));
		else
			return (write(1, &buff[SIZE_B - i - 1], w - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1))
}
/**
 * printer - this function Prints a string
 * @list: gives out arguments
 * @typ:  types of the characters.
 * @buff:  array of buffer to hold print
 * @flags:  Calculates active flags
 * @w: to get thewidth.
 * @pr: specifies precision
 * @s: specifies size
 *
 * Return: Number of chars printed.
 */
int printer(int list, int typ, char buff[],
	int f, int w, int pr, int s)
{
	int l = SIZE_BUFF - typ - 1;
	char paddind = ' ', extra = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (list)
		extra= '-';
	else if (f & F_PLUS)
		extra = '+';
	else if (f & F_SPACE)
		extra = ' ';

	return (number_write(typ, buff, f, w, pr,
		l, paddind, extra));
}

/**
 * number_write - functuin to Write a num using a bufffer
 * @typ: numb where index starts
  * @buff: is the Buffer
 * @f: for flags
 * @w : width
 * @pr: specifies Precision 
 * @l:  length
 * @pading: Pading char
 * @exta: Extra char
 *
 * Return: Number of printed chars.
 */
int number_write(int typ, char buff[],
	int f, int w, int pr,
	int l, char pading, char extra)
{
	int i, starting = 1;

	if (pr == 0 && typ == SIZE_B - 2 && buff[typ] == '0' && w == 0)
		return (0);
	if (pre > 0 && pr < l)
		pading = ' ';
	while (pr > l)
		buff[--typ] = '0', l++;
	if (extra != 0)
		l++;
	if (w > l)
	{
		for (i = 1; i < w - l + 1; i++)
			buff[i] = pading;
		buff[i] = '\0';
		if (f & F_MINUS && pading == ' ')
		{
			if (extra)
				buff[--typ] = extra;
			return (write(1, &buff[typ], l) + write(1, &buff[1], i - 1));
		}
		else if (!(f & F_MINUS) && pading == ' ')
		{
			if (extra)
				buff[--typ] = extra;
			return (write(1, &buff[1], i - 1) + write(1, &buff[typ], l));

		}
			else if (!(f & F_MINUS) && pading == '0')
		{
			if (extra)
				buff[--start] = extra;
			return (write(1, &buff[start], i - start) +
				write(1, &[typ], l - (1 - start)));
		}
	}
	if (extra)
		buff[--typ] = extra;
	return (write(1, &buff[typ], l));
}

/**
 * unsgnd_write - Writes the unsigned number
 * @list: list num is -tive
 * @txt: Index at which the number starts
 * @buff: Array 
 * @f: Flags
 * @w: Width 
 * @pr: Precision 
 * @size: Size
 *
 * Return: No.of chars.
 */
int unsgnd_write(int list, int txt,
	char buff[],
	int f, int w, int pr, int s)
{
	
	int l = SIZE_B - txt - 1, i = 0;
	char padd = ' ';

	UNUSED(list);
        UNUSED(s);
	if (p == 0 && txt == SIZE_B - 2 && buff[txt] == '0')
		return (0);

	if (pr > 0 && pr < l)
		pading = ' ';

	while (pr > l)
	{
		buff[--txt] = '0';
		l++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		pading = '0';

	if (w > l)
	{
		for (i = 0; i < w - l; i++)
			buff[i] = pading;

		buff[i] = '\0';

		if (f & F_MINUS)
		{
			return (write(1, &buff[txt], l) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[txt], l));
		}
	}

	return (write(1, &buff[txt], l));
}

/**
 * pointer_write - Write to a memory addr
 * @buff: Arrays 
 * @txt: Index
 * @l: Length 
 * @w: Width 
 * @f: Flags
 * @pading: padding
 * @extra:  extra char
 * @start: padding should start
 *
 * Return: Number of written chars.
 */
int pointer_write(char buff[], int txt, int l,
	int w, int f, char pading, char extra, int start)
{
	int i;

	if (w > l)
	{
		for (i = 3; i < w - l + 3; i++)
			buff[i] = pading;
		buff[i] = '\0';
		if (f & F_MINUS && pading == ' ')
		{
			buff[--txt] = 'x';
			buffer[--txt] = '0';
			if (extra)
				buff[--txt] = extra;
			return (write(1, &buff[txt], l) + write(1, &buff[3], i - 3));
		}
		else if (!(f & F_MINUS) && pading == ' ')
		{
			buff[--txt] = 'x';
			buff[--txt] = '0';
			if (extra)
				buff[--txt] = extra;
			return (write(1, &buff[3], i - 3) + write(1, &buff[txt], l));
		}
		else if (!(f & F_MINUS) && pading == '0')
		{
			if (extra)
				buff[--start] = extra;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[start], i - start) +
				write(1, &buff[txt], l - (1 - start) - 2));
		}
	}
	buff[--txt] = 'x';
	buff[--txt] = '0';
	if (extra)
		buff[--txt] = extra;
	return (write(1, &buff[txt], SIZE_B - txt - 1));
}
