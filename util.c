#include "shell.h"

/**
 * tc - Returns the token count of a string, each one separated by a
 * specified delimiter.
 * @str: provided string
 * @delim: charset for delimiters
 *
 * Return: token count of the string.
 */
int tc(char *str, char *delim)
{
	int i, c;

	if (!str)
		return (0);

	for (i = 0, c = 0; str[i]; i++)
		if (!charcmp(str[i], delim) && (charcmp(str[i + 1], delim) || !str[i + 1]))
			c++;

	return (c);
}

/**
 * fc - Returns the field count of a string, each one enclosed by a
 * specified delimiter.
 * @str: provided string
 * @delim: charset for delimiters
 *
 * Return: field count of the string.
 */
int fc(char *str, char delim)
{
	int i, c;

	if (!str)
		return (0);

	for (i = 0, c = 0; str[i]; i++)
		if (str[i] == delim)
			c++;

	return (c);
}

/**
 * _tokenize - tokenizes a string
 * @buffer: string
 * @delimiter: charset for the delimiter
 *
 * Return: double pointer with every token
 */
char **_tokenize(char *buffer, char *delimiter)
{
	int i = 0;
	char *token, *cbuffer;
	char **store_tokens = NULL;

	cbuffer = malloc(sizeof(*cbuffer) * _strlen(buffer) + 1);
	_strcpy(cbuffer, buffer);

	store_tokens = malloc(sizeof(char *) * tc(buffer, delimiter) + 8);

	token = _strtok(cbuffer, delimiter);

	store_tokens[i] = malloc(sizeof(*token) * _strlen(token) + 1);
	_strcpy(store_tokens[i], token);

	while ((token = _strtok(NULL, delimiter)))
	{
		store_tokens[++i] = malloc(sizeof(*token) * _strlen(token) + 1);
		_strcpy(store_tokens[i], token);
	}

	store_tokens[++i] = NULL;
	free(cbuffer);
	return (store_tokens);
}

/**
 * _strtok - returns the next token of a string, delimited with a
 * provided set of characters
 * @str: provided string
 * @delim: character set for delimiters
 *
 * Return: pointer to the next token (word), if there are no tokens left, the
 * function will return a null pointer.
 */
char *_strtok(char *str, char *delim)
{
	int i, len;
	static char *token, *cpy;
	static int pos, slen;

	if (str && !tc(str, delim))
		return (NULL);
	if (!str && !cpy)
		return (NULL);
	if (str && cpy)
		pos = 0;
	if (str && (str != cpy))
	{
		cpy = str;
		slen = _strlen(cpy);
	}
	if ((!cpy || !token) && str)
	{
		cpy = str;
		slen = _strlen(cpy);
		pos = 0;
	}

	for (i = pos, len = 0; cpy[i]; i++)
	{
		if (!charcmp(cpy[i], delim))
			len++;
		if (!charcmp(cpy[i], delim) && (charcmp(cpy[i + 1], delim) || !cpy[i + 1]))
		{
			token = &cpy[(i + 1) - len];
			token[len] = 0;
			if (i + 1 == slen)
				pos = i + 1;
			else
				pos = i + 2;
			return (token);
		}
	}
	token = NULL;
	return (token);
}

/**
 * _strfield - Returns an array of fields from a string.
 * @str: provided string
 * @delim: delimiter
 *
 * Return: array with every field from the string, NULL terminated
 * and separated through a delimeter.
 */
char **_strfield(char *str, char delim)
{
	int i = 0, j = 0, k = 0, l = 0, len = 0;
	char **list;
	int pos = 0;

	if (!str || !fc(str, delim))
		return (NULL);

	list = malloc(sizeof(char *) * fc(str, delim) + 8);
	if (!list)
	{
		free(list);
		return (NULL);
	}
	if (str[0] == delim)
	{
		list[0] = malloc(1);
		_strcpy(list[0], "");
		l++;
	}

	for (i = pos; str[i];)
	{
		if (str[i] == delim && str[i + 1])
		{
			k = 0;
			len = 0;
			i++;
			j = i;
			for (; str[i] != delim && str[i] != 0; i++)
				len++;
			list[l] = malloc(i + 1);
			for (; k < len ; j++, k++)
				list[l][k] = str[j];
			list[l][k] = 0;
			l++;
		}
		else
			i++;
	}
	return (list);
}
