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
 * @format: First arg
 *
 * Return: int
 */
int check_str(int i, int sum, int a, va_list to, const char *format)
{
	int num;
	bool is = 0;

	for (i = 0; i < a; i++)
	{
		is = (*(format + i) == 'd' || *(format + i) == 'i');
		if (i > 0 && *(format + i - 1) == '%' && *(format + i) == 'c')
		{
			print_char(va_arg(to, int));
			sum++;
		}
		else if (i > 0 && *(format + i - 1) == '%' && *(format + i) == 's')
		{
			print_str(va_arg(to, char *));
			sum += _len(va_arg(to, char *));
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

	if (format == NULL)
	{
		return (0);
	}
	length = _len(format);
	va_start(to, format);
	sum = check_str(i, sum, length, to, format);
	va_end(to);
	return (sum);
}
