#include "shell.h"

/**
 * my_exit - it exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int my_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			_eputs(info->argv[1]);
			print_error(info, "Illegal_ number: ");
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always return 0
 */
int cd(info_t *info)
{
	char *m, *dir, buffer[1024];
	int chdir_ret;

	m = getcwd(buffer, 1024);
	if (!m)
		_puts("TODO: >>getcwd fail emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "Home=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_putchar('\n');
			_puts(s);
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		_eputs(info->argv[1]), _eputchar('\n');
		print_error(info, "can't cd to ");
	}
	else
	{
		_setenv(info, "PWD", getcwd(buffer, 1024));
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	}
	return (0);
}

/**
 * help - display a help message
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always return 0
 */
int help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
