#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - function that produces output according to a format
 * @format: a character string.
 * @...: veriadic argument
 *
 * Return: the number of characters printed.
 *
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

					fputs(s, stdout);
					count += strlen(s);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
