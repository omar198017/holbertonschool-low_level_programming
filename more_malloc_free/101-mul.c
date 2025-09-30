#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * is_digit - checks if a string contains only digits
 * @s: string to evaluate
 *
 * Return: 1 if true, 0 otherwise
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * errors - prints error and exits
 */
void errors(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, carry, n1, n2, *result, total_len, start = 0;

	if (argc != 3)
		errors();

	num1 = argv[1], num2 = argv[2];
	if (!is_digit(num1) || !is_digit(num2))
		errors();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	total_len = len1 + len2;
	result = calloc(total_len, sizeof(int));
	if (!result)
		errors();

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	/* Skip leading zeros */
	while (start < total_len && result[start] == 0)
		start++;

	if (start == total_len)
		_putchar('0');
	else
	{
		for (i = start; i < total_len; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
