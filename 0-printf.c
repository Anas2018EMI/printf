#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

/* betty style doc for function  check_format0 goes there */
/**
 * check_format0 - Entry point
 * @specifier: first arg
 * @args: second arg
 *
 * Return: int
 */
int check_format0(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'b')
	{
		count += print_binary(va_arg(args, int));
	}
	return (count);
}
/* betty style doc for function  check_format goes there */
/**
 * check_format - Entry point
 * @specifier: first arg
 * @args: second arg
 *
 * Return: int
 */
int check_format(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		count += print_char(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		count += print_str(va_arg(args, char *));
	}
	else if (specifier == '%')
	{
		count += print_char('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		count += print_number(va_arg(args, int));
	}
	else
	{
		count += print_char('%');
		count += print_char(specifier);
	}
	return (count);
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
	int i = 0, sum = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			sum += print_char(format[i]);
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				return (-1);
			}
			else if (format[i] == 'b')
			{
				sum += check_format0(format[i], args);
			}
			else
			{
				sum += check_format(format[i], args);
			}
		}
		i++;
	}
	va_end(args);
	return (sum);
}
