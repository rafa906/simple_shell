#include "shell.h"

/**
 * histooryy - it displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always return 0
 */
int histooryy(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * No_alias - it sets alias to string
 * @info: parameter structure
 * @str: the string alias
 *
 * Return: Always return 0 on success, And return 1 on error
 */
int No_alias(info_t *info, char *str)
{
	char *m, e;
	int ret;

	p = _strchr(str, '=');
	if (!m)
		return (1);
	e = *m;
	*m = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*m = e;
	return (ret);
}

/**
 * alias - sets alias to string
 * @info: parameter structure
 * @str: the string alias
 *
 * Return: Always return 0 on success, And return 1 on error
 */
int alias(info_t *info, char *str)
{
	char *m;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	if (!*++m)
		return (unset_alias(info, str));

	No_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string , it checks if node is not full
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *m = NULL, *a = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');
		for (a = node->str; a <= m; a++)
		_putchar('\'');
		_putchar(*a);
		_puts(m + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - used to create and manipulate aliases in a shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always return 0
 */
int my_alias(info_t *info)
{
	int i = 0;
	char *m = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		m = _strchr(info->argv[i], '=');
		if (m)
			alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
