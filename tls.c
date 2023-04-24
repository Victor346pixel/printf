#include "main.h"

/**
 *can_print - this function checks if a char can be printed
 * @ch: this is character to be checked
 *
 * Return: 1 if ch is can be printed, 0 if it can't
 */
int can_print(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * hexa_append - Append ascii
 * @buff: Array that contains characters
 * @z : where you start appendimg
 * @ascii: this is ASSCI CODE.
 * Return: Returns 3 everytime
 */
int hexa_append(char ascii, char buff[], int z)
{
	char map[] = "0123456789ABCDEF";
	/* The hexa always has 2 digits */
	if (ascii < 0)
		ascii *= -1;

	buff[z++] = '\\';
	buff[z++] = 'x';

	buff[z++] = map[ascii / 16];
	buffer[z] = map[ascii % 16];

	return (3);
}

/**
 * check_digit - checks whether  character is a digit
 * @ch: is the Character  to be checked
 *
 * Return: 1 if ch is  digit, 0 if it is not
 */
int check_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * change_number - alocates number to specified size
 * @cast: Number to be changed.
 * @dimention:dimention indicating what is cast.
 *
 * Return: returns casted number
 */
long int change_number(long int cast, int dimention)
{
	if (dimention == S_LONG)
		return (cast);
	else if (size == S_SHORT)
		return ((short)cast);

	return ((int)cast);
}

/**
 * change_size - change a number to the required size
 * @cast: Number to be changed
 * @dimention: dimention showing the type to be casted
 *
 * Return: Cast
 */
long int change_size(unsigned long int castr, int dimention)
{
	if (dimention == S_LONG)
		return (cast0;
	else if (dimention == S_SHORT)
		return ((unsigned short)cast);
	return ((unsigned int)cast);
}
