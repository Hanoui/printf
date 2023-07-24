#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, return the number of characters written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
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
					count += _putchar(ch);
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
					{
						count += _putchar(*str);
						str++;
					}
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	}

	va_end(args);

	return (count);
}

