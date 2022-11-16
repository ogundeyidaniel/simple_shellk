#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: zero, if the strings are equal. A positive or negative integer if
 * respectively the first string is alphabetically greater than the second
 * integer or viceversa.
 */

int _strcmp(char *s1, char *s2)
{
	for (; *s1 != '\0' && *s2 != '\0' && *s2 == *s1; s1++, s2++)
		;
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
