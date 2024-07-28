#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
/* betty style doc for function  print_number goes there */
/**
 * print_number - Entry point
 * @n: First arg
 * Return: int
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		print_char('-');
		num = -n;
		count++;
	}
	else
		num = n;

	if (num / 10)
		count += print_number(num / 10);

	print_char((num % 10) + '0');
	return (count + 1);
}
