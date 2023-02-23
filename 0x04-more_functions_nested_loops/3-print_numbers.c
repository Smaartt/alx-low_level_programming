#include "main.h"
/**
* print_numbers - checks for checks for a digit (0 through 9).
**
Return: Always 0.
*/

void print_numbers(void)
{
	int ch;

	for (ch = 48; ch < 58; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}
