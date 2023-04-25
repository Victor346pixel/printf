#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024




#define S_SHORT 1
#define S_LONG  2

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


#define F_MINUS 1
#define F_SPACE 16
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*strings */
int print_char(va_list t, char buff[],
	int f, int w, int p, int s);
int print_string(va_list t, char buff[],
	int f, int w, int p, int s);
int print_percent(va_list t, char buff[],
	int f, int w, int p, int s);

/* Functions to print numbers */
int print_int(va_list t, char buff[],
	int f, int w, int p, int s);
int print_binary(va_list t, char buff[],
	int f, int w, int p, int s);
int print_unsigned(va_list t, char buff[],
	int f, int w, int p, int s);
int print_octal(va_list t, char buff[],
	int f, int w, int p, int s);
int print_hexadecimal(va_list t, char buff[],
	int f, int w, int p, int s);
int print_hexa_upper(va_list types, char buffer[],
	int f, int w, int p, int s);

int print_hexa(va_list t, char map_to[],
char buff[], int f, char f_ch, int w int p, int s);

/* non printable characters */
int print_non_printable(va_list t, char buff[],
	int f, int w, int p, int s);

/* print memory address */
int print_pointer(va_list t, char buff[],
	int f, int w, int p, int s);

/* ******handle other specifiers */
int flags(const char *formt, int *n);
int width(const char *frmt, int *i, va_list ls);


	
/****************** TLS ******************/
int can_print(char);
int hexa_append(char, char[], int);
int check_digit(char);

long int change_number(long int cast, int dimention);
long int change_size (long int cast, int dimention);

/* write handlers  */
int handle_char(char ch, char buff[],
	int f, int w, int pr, int s);
int printer(int list, int typ, char buff[],
	int f, int w, int pr, int s);
int number_write(int typ, char buff[], int f, int w, int pr,
	int l, char pading, char extra);
int pointer_write(char buff[], int txt, int l,
	int w, int f, char pading, char extra, int write_pointerstart);

#endif /* MAIN_H */



