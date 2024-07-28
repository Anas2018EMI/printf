#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

/* betty style doc for function  print_char goes there */
/**
 * print_char - Entry point
 * @c: First arg
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
/* betty style doc for function print_str goes there */
/**
 * print_str - Entry point
 * @str: First arg
 *
 * Return: int
 */
int print_str(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}
