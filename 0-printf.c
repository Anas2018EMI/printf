#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

/* betty style doc for function  check_str goes there */
/**
 * check_str - Entry point
 * @i: first arg
 * @sum: second arg
 * @a: third arg
 * @to: seventh arg
 * @is: eighth arg
 * @format: First arg
 *
 * Return: int
 */
int check_str(int i, int sum, int a, va_list to, bool is, const char *format)
{
	int num;
	char c;
	char *str;

	for (i = 0; i < a; i++)
	{
		if (i > 0 && *(format + i - 1) == '%' && *(format + i) == 'c')
		{
			c = va_arg(to, int);
			print_char(c);
			sum++;
		}
		else if (i > 0 && *(format + i - 1) == '%' && *(format + i) == 's')
		{
			str = va_arg(to, char *);
			print_str(str);
			sum += _len(str);
		}
		else if (i > 0 && *(format + i - 1) == '%' && is)
		{
			num = va_arg(to, int);
			sum += print_number(num);
		}
		else if (i > 0 && *(format + i - 1) == '%' && *(format + i) == '%')
		{
			print_char(*(format + i));
			sum++;
		}
		else if (*(format + i) != '%')
		{
			print_char(*(format + i));
			sum++;
		}
		else
		{
			continue;
		}
	}
	return (sum);
}

/* betty style doc for function  _printf goes there */
/**
 * _printf - Entry point
 * @format: First arg
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, sum = 0, length;
	va_list to;
	bool is = *(format + i) == 'd' || *(format + i) == 'i';

	if (format == NULL)
	{
		return (0);
	}
	length = _len(format);
	va_start(to, format);
	sum = check_str(i, sum, length, to, is, format);
	va_end(to);
	return (sum);
}

