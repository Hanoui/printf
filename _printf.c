#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * print_char - Prints a single character.
 * @args: The va_list containing the character to print.
 * @count: The pointer to the character count.
 */
void print_char(va_list args, int *count)
{
	char ch = va_arg(args, int);
	_putchar(ch);
	(*count)++;
}

/**
 * print_string - Prints a string of characters.
 * @args: The va_list containing the string to print.
 * @count: The pointer to the character count.
 */
void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	while (*str)
	{
		_putchar(*str);
		str++;
		(*count)++;
	}
}

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
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return count;
}

