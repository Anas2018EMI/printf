#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
/* betty style doc for function  print_number goes there */
/**
 * print_number - Entry point
 * @num: First arg
 * Return: int
 */
int print_number(int num)
{
	int i = 10, j = 0, k, l, sum = 0;
	int *num2, *dec;

	if (num < 0)
	{
		num = -num;
		print_char('-');
	}
	while (num / i != 0)
	{
		j++;
		i *= 10;
	}
	i /= 10;
	num2 = malloc(sizeof(int) * (j + 1));
	dec = malloc(sizeof(int) * (j + 1));
	l = 1;
	for (k = 0; k < j + 1; k++)
	{
		*(dec + k) = l;
		l *= 10;
	}
	*num2 = num / i;
	print_char(*num2 + 48);
	for (k = 1; k < j + 1; k++)
	{
		i /= 10;
		sum = 0;
		for (l = 0; l < k; l++)
		{
			sum += *(num2 + l) * dec[k - l];
		}
		*(num2 + k) = num / i - sum;
		print_char(*(num2 + k) + 48);
	}
	free(num2);
	free(dec);
	return (j + 1);
}

