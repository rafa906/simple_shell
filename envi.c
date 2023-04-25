#include "shell.h"

/**
 * my_env - prints the current environment by calling the print_list_str function
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always return 0
 */
int my_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_enviro - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char get_enviro(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *m;

	while (node)
	{
		m = starts_with(node->str, name);
		if (m && *m)
			return (m);
		node = node->next;
	}
	return (NULL);
}

/**
 * _my_setenviro - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always return 0
 */
int _my_setenviro(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("There is incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable by calling _myunsetenv functions for each name passed 
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("There is Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_envlist - initialize the env linked list with the value from environ global variable
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_envlist(info_t *info)
{
	size_t i;
	list_t *node = NULL;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
