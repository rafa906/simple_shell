#include "shell.h"

/**
 * _freees - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise return 0.
 */
int _freees(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

