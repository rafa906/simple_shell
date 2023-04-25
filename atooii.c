#include "shell.h"

/**
 * inter_active - returns true if shell is running in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode and return 0 otherwise
 */
int inter_active(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * issdelim - checks if given character is a delimeter or not by comparing it each character in delim string
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int issdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * isalphaa - check if given character is alphabetic character or not
 * @c: The character to input
 * Return: 1 if c is alphabetic and return 0 otherwise
 */

int isalphaa(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atooii - converts a given string to an integer b
 * @m: the string to be converted
 * Return: 0 if no numeric characters in string, converted number otherwise
 */

int _atooii(char *m)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; m[i] != '\0' && flag != 2; i++)
	{
		if (m[i] == '-')
			sign *= -1;

		if (m[i] >= '0' && m[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (m[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
