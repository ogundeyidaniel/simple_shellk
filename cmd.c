#include "shell.h"

/**
 * ctrl_c - disables the process from getting terminated using SIGINT
 * @sig: signal
 *
 * Return: void.
 */
void ctrl_c(int sig __attribute__ ((unused)))
{
}

/**
 * _get_input - gets input from stdin.
 * @env: environment
 *
 * Return: void.
 */
void _get_input(char *env[])
{
	char *buffer = _next(), *cbuffer = NULL;

	cbuffer = malloc(sizeof(*cbuffer) * _strlen(buffer) + 1);
	_strcpy(cbuffer, buffer);

	if (_strtok(cbuffer, " \n\t\r"))
	{
		free(cbuffer);
		_validate(buffer, env);
		_get_input(env);
	}
	else
	{
		free(cbuffer);
		free(buffer);
		_get_input(env);
	}
}

/**
 * _next - gets input through getline and returns the associated buffer
 *
 * Return: void.
 */
char *_next(void)
{
	int input;
	char *buffer = NULL;
	size_t bufsize = 0;

	show_prompt();
	signal(SIGINT, ctrl_c);
	input = getline(&buffer, &bufsize, stdin);
	if (input == EOF)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}

/**
 * _validate - validates input from _next
 * @buffer: buffer containing the command
 * @env: environment
 *
 * Return: void.
 */
void _validate(char *buffer, char *env[])
{
	char **argv = NULL;

	argv = _tokenize(buffer, " \n\t\r");
	free(buffer);

	if (check_for_builtins(argv, env) == NULL)
	{
		if (check_path(argv, env))
			_execute(argv, env);
		else
		{
			if (access(argv[0], X_OK) == 0)
				_execute(argv, env);
			else
			{
				_putstr(argv[0]);
				_putstr(": command not found\n");
			}
		}
		free_double((void **) argv, ec((void **) argv));
	}
}

/**
 * _execute - executes a command
 * @argv: arguments
 * @env: environment
 *
 * Return: void.
 */
void _execute(char *argv[], char *env[])
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror("Could not execve");
		exit(0);
	}
	else if (pid < 0)
		perror("Could not execve");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
