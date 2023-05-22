#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/**
 * struct alias_s - a struct that represents an alias.
 * @name: the alias name.
 * @value: the alias value.
 * @next: a pointer to the next alias in the list.
 * Description: This typedef defines an alias_t type
 * that is a struct with three fields.
 */

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/**
 * struct builtin_s - a struct that represents a builtin command.
 * @name: the name of the builtin command.
 * @f: a pointer to a function that executes the builtin command.
 * Description: typedef defines a builtin_t type is a struct with two fields.
 */

typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */

typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/* Global aliases linked list */
alias_t *aliases;

/* Global environemnt */
extern char **environ;

/* Global program name */
char *progra_name;

/* Global history counter */
int history;
