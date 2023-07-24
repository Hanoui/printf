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
	char ch;
	char *str;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				ch = (char)va_arg(args, int);
				putchar(ch);
				count++;
				break;
			case 's':
				str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					str++;
					count++;
				}
				break;
			case '%':
				putchar('%');
				count++;
				break;
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
 * print_number - Prints a number recursively.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10 != 0)
	{
		print_number(num / 10);
	}

	putchar((num % 10) + '0');
	return (1);
}

