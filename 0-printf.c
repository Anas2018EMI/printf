#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

/* betty style doc for function  handle_format goes there */
/**
 * handle_format - Entry point
 * @specifier: first arg
 * @args: second arg
 *
 * Return: int
 */
int handle_format(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count += print_char(va_arg(args, int));
			break;
		case 's':
			count += print_str(va_arg(args, char *));
			break;
		case '%':
			count += print_char('%');
			break;
		case 'd':
		case 'i':
			count += print_number(va_arg(args, int));
			break;
		default:
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
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
			sum += print_char(format[i]);
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			sum += handle_format(format[i], args);
		}
		i++;
	}

	va_end(args);
	return (sum);
}

