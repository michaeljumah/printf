#include <stdarg.h>
#include <stdio.h>
#include "main.h"
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
	unsigned int printed_char = 0;

	va_start(args, format);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			++p;
			if (*p == 'c')
				printed_char = printChar(args, printed_char);
			else if (*p == 's')
				printed_char = printStr(args, printed_char);
			else if (*p == 'd' || *p == 'i')
				printed_char = printInt(args, printed_char);
			else if (*p == 'u')
				printed_char = printUsign(args, printed_char);
			else if (*p == 'o')
				printed_char = printOctal(args, printed_char);
			else if (*p == 'x')
				printed_char = printHexLow(args, printed_char);
			else if (*p == 'X')
				printed_char = printHexUp(args, printed_char);
			else if (*p == 'b')
				printed_char = printBinary(args, printed_char);
			else if (*p == '%')
			{
				putchar('%');
				++printed_char;
			}
		}
		else
		{
			putchar(*p);
			++printed_char;
		}
		++p;
	}
	va_end(args);
	return (printed_char);
}
