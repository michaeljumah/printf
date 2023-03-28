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

	const char *p = format;
	int chars_printed = 0;

	va_start(args, format);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			++p;
				if (*p == 'c')
				{
					char c = va_arg(args, int);

					putchar(c);
					++chars_printed;
				}
				else if (*p == 's')
				{
					char *str = va_arg(args, char *);

					fputs(str, stdout);
					chars_printed += strlen(str);
				}
				else if (*p == '%')
				{
					putchar('%');
					++chars_printed;
				}
		}
		else
		{
			putchar(*p);
			++chars_printed;
		}
		++p;
	}
	va_end(args);
	return (chars_printed);
}
