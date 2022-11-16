#include "shell.h"

/**
 * main - start msh
 * @argc: argument count
 * @argv: argument variables
 * @environment: environment variables
 *
 * Return: zero..
 */
int main(int argc __attribute__((unused)),
		char **argv __attribute__((unused)), char **environment)
{
	_get_input(environment);

	return (0);
}
