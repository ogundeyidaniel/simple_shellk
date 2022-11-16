 #include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @argv: arguments
 * @env: current enviroment
 * Return: pointer to the function or NULL
 */

void (*check_for_builtins(char *argv[], char *env[]))(char *env[])
{
	int i;

	builtin_t check[] = {
		{"exit", n_exit},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(argv[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
	{
		free_double((void **) argv, ec((void **) argv));
		check[i].f(env);
	}

	return (check[i].f);
}

/**
* n_exit - exit shell
* @env: current enviroment
*/

void n_exit(char *env[])
{
	if (env)

	exit(0);
}

/**
* _env - prints enviroment
* @env: current enviroment
*/

void _env(char *env[])
{
	int i = 0;

	while (env[i])
	{
		_putstr(env[i]);
		_putstr("\n");
		i++;
	}
}
