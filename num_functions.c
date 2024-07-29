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
	{
		count += print_number(num / 10);
	}
	print_char((num % 10) + '0');
	return (count + 1);
}
/* betty style doc for function  print_binary goes there */
/**
 * print_binary - Entry point
 * @n: First arg
 * Return: int
 */
int print_binary(unsigned int n)
{
	int count = 0;
	int binary[32];
	int i = 0;

	if (n == 0)
	{
		return (print_char('0'));
	}
	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (i = i - 1; i >= 0; i--)
	{
		count += print_char(binary[i] + '0');
	}
	return (count);
}
