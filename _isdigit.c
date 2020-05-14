#include "monty.h"

/**
 * _isdigit - function to check if character is a digit
 * @c: input character to check if digit
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
