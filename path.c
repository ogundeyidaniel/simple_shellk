#include "shell.h"

/**
 * check_path - checks if command is present in PATH.
 * @argv: arguments
 * @env: environment
 *
 * Return: if the command is found, the function will return 1. Else, the
 * function will return 0.
 */
int check_path(char *argv[], char *env[])
{
	char *path = _path(env), *check = NULL, **routes = NULL;
	struct stat buf;
	int i = 0;

	if (path != NULL && *path)
	{
		if (check_cwd(argv))
			return (1);
		routes = _tokenize(path, ": ");
		check = expand(check, 0, (sizeof(*check) * _strlen(routes[i]))
				+ (sizeof(*check) * _strlen(argv[0]) + 2));
		while (routes[i])
		{
			_strcpy(check, routes[i]);
			_strcat(check, "/");
			_strcat(check, argv[0]);
			if (stat(check, &buf) == 0)
			{
				free(argv[0]);
				argv[0] = check;
				free_double((void **) routes, ec((void **) routes));
				return (1);
			}
			_memset(check, 0, _strlen(check));
			i++;
			if (routes[i])
				check = expand(check, sizeof(check), (sizeof(*check) * _strlen(routes[i]))
						+ (sizeof(*check) * _strlen(argv[0]) + 2));
		}
		free_double((void **) routes, ec((void **) routes));
		free(check);
	}
	return (0);
}
/**
 * _path - checks for the environment variable PATH.
 * @env: environment
 *
 * Return: pointer to the environment variable PATH, five steps forward.
 */
char *_path(char **env)
{
	int i = 0, j = 0;
	char *path = "PATH=";

	while (env[i])
	{
		j = 0;
		while (j < 5)
		{
			if (env[i][j] != path[j])
				break;
			j++;
		}
		if (j == 5)
			break;
		i++;
	}
	return (&env[i][j]);
}

/**
 * cwd - current working diretory
 *
 * Return: char * containing the absolute current working directory
 */
char *cwd()
{
	char *cwd = NULL;

	return (getcwd(cwd, 0));
}

/**
 * absolute_path - get absolute path using the current working directory.
 * @path: path to the executable
 *
 * Return: generated absolute path
 */
char *absolute_path(char *path)
{
	char *wd = cwd();
	char *ab_path = malloc((sizeof(*ab_path) * _strlen(wd)) +
			(sizeof(*ab_path) * _strlen(path)) + 2);

	_strcpy(ab_path, wd);
	_strcat(ab_path, "/");
	_strcat(ab_path, path);

	free(wd);
	return (ab_path);
}

/**
 * check_cwd - checks if path from absolute current working directory exits.
 * @argv: arguments
 *
 * Return: if path exists, the function will return 1, else, the function
 * will return 0.
 */
int check_cwd(char *argv[])
{
	char *check = NULL;
	struct stat buf;

	if (argv[0][0] == '.' && argv[0][1] == '/')
	{
		check =	absolute_path(&argv[0][2]);
		if (stat(check, &buf) == 0)
		{
			free(argv[0]);
			argv[0] = check;
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}
