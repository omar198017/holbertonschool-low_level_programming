#include <stdlib.h>
#include "main.h"

/**
 * is_digit - checks if a string contains only digits
 * @s: string to evaluate
 *
 * Return: 1 if all digits, 0 otherwise
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
 * print_error - prints "Error" and exits with 98
 */
void print_error(void)
{
	char *err = "Error\n";

	while (*err)
		_putchar(*err++);
	exit(98);
}

/**
 * multiply - multiplies two positive numbers
 * @num1: first number string
 * @num2: second number string
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2);
	int *result, total_len = len1 + len2;
	int i, j, carry, n1, n2, start = 0;

	result = calloc(total_len, sizeof(int));
	if (!result)
		print_error();

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
}

/**
 * main - validates input and calls multiplication
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);
	return (0);
}
