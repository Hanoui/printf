#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					count += print_number(va_arg(args, int));
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_number - Prints a number.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		putchar('-');
		count++;
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	putchar((n % 10) + '0');
	count++;

	return (count);
}

