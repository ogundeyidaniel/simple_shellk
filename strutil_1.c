#include "shell.h"

/**
 * _putstr - writes a string to stdout
 * @str: The string to print
 * Return: size of string or -1.
 */
int _putstr(char *str)
{
	int size = -1, len = 0;

	while (str[len] != '\0')
		len++;

	size = write(1, str, len);

	if (len == size)
		return (size);

	/*error*/
	return (size);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (*src == '\0')
		*dest = '\0';

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);

	if (*(src + i) == '\0')
		*(dest + i) = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	char *str;

	str = dest;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++, i++)
		str[i] = src[j];

	str[i] = '\0';

	return (str);
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 * Return: i, length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	for (; s[i] != '\0'; i++)
		;
	return (i);

}

/**
 * charcmp - compares a provided character with each one provided in a charset.
 * @c: provided character
 * @cmp: charset for comparison
 *
 * Return: if the character matches with the charset, the function will
 * return 1. Else, the function will return 0.
 */
int charcmp(char c, char *cmp)
{
	int i;

	for (i = 0; cmp[i]; i++)
		if (c == cmp[i])
			return (1);
	return (0);
}
