#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int b, mint = 0;
	unsigned long int soft;

	for (b = 63; b >= 0; b--)
	{
		soft = n >> b;

		if (soft & 1)
		{
			_putchar('1');
			 mint++;
		}
		else if (mint)
			_putchar('0');
	}
	if (!mint)
		_putchar('0');
}


