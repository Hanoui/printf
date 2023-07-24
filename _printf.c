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
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					break;
				case 's':
					for (char *str = va_arg(args, char *); *str; str++)
						putchar(*str);
					break;
				case '%':
					putchar('%');
					break;
				default:
					putchar('%');
					putchar(*format);
					break;
			}
		}
		else
		{
			putchar(*format);
		}

		format++;
		count++;
	}

	va_end(args);

	putchar(*format);
}

