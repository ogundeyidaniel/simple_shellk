#ifndef _shell_
#define _shell_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

/**
 * struct builtin - shell builtin
 * @name: builtin name
 * @f: function associated with the builtin
 *
 */
typedef struct builtin
{
	char *name;
	void (*f)(char *env[]);
} builtin_t;

void _get_input(char *env[]);
char *_next(void);
void show_prompt(void);
void _validate(char *buffer, char *env[]);
void _execute(char *argv[], char *env[]);

int tc(char *str, char *delim);
char **_tokenize(char *buffer, char *delimiter);
char *_strtok(char *str, char *delim);
char **_strfield(char *str, char delim);

int _putstr(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *a, char *b);
int _strlen(char *s);
int charcmp(char c, char *cmp);
int _strcmp(char *s1, char *s2);

char *_path(char **env);
int check_path(char *argv[], char *env[]);
char *cwd();
char *absolute_path(char *path);
int check_cwd(char *argv[]);

int ec(void **ptr);

void *_memset(char *s, int c, size_t n);
void free_double(void **ptr, int i);
void *expand(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

void (*check_for_builtins(char **argv, char *env[]))(char *env[]);
void n_exit(char *env[]);
void _env(char *env[]);

#endif
