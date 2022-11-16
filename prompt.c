#include "shell.h"

/**
 * show_prompt - shows the prompt.
 *
 * Return: void.
 */
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_putstr(GREEN "[._.] ");
		_putstr(YELLOW ">> " RESET);
	}
}
