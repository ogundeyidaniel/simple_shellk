#include "shell.h"

/**
 * ec - element count for NULL terminated double pointers
 * @ptr: pointer
 *
 * Return: element count of ptr.
 */
int ec(void **ptr)
{
	int i;

	for (i = 0; ptr[i] ; i++)
		;

	return (i);
}
