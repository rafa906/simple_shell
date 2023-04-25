#include "shell.h"

/**
 * erroratoii -it converts a string to an integer
 * @l: the string to be converted
 * Return: 0 if there is no numbers in string, converted number otherwise
 *       return -1 on error
 */
int erroratoii(char *l)
{
	int i = 0;
	unsigned long int result = 0;

	if (*l == '+')
		l++;  /* TODO: why does this make main return 255? */
	for (i = 0;  l[i] != '\0'; i++)
	{
		if (l[i] >= '0' && l[i] <= '9')
		{
			result *= 10;
			result += (l[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error -it prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return:return 0 if there is no numbers in string, converted number otherwise
 *        return -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_decimal - function prints a decimal (integer) number to afile descriptor 
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int input, int fd)
{
	int i, count = 0;
	int (*__putchar)(char) = _putchar;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		__putchar('-');
		_abs_ = -input;
		count++;
	}
	else
	current = _abs_;
	_abs_ = input;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converts a number to string in the specified base 
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	static char *array;
	char *ptr;
	char sign = 0;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always return 0;
 */
void _removingcomments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
