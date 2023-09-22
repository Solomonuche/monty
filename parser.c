#include "monty.h"
char **parser(char *buf);
/**
 * parser - a function that parser a string into a token
 * @buf: input string
 *
 * Return: (tokens)
 */

char **parser(char *buf)
{
	char *token = NULL;
	int i = 0, j = 0;
	char *delim = " \n";
	char *buf_cpy = strdup(buf);

	if (buf_cpy == NULL)
	{
		free(buf);
		malloc_error();
	}

	token = strtok(buf_cpy, delim);

	while (token != NULL)
	{
		gvar->argc++;
		token = strtok(NULL, delim);
	}

	gvar->argv = (char **)malloc((gvar->argc + 1) * sizeof(char *));
	if (gvar->argv == NULL)
	{
		free(buf);
		free(buf_cpy);
		malloc_error();
	}

	token = strtok(buf, delim);

	while (token != NULL)
	{
		gvar->argv[i] = strdup(token);
		if (gvar->argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(gvar->argv[j]);
			}
			free(gvar->argv);
			free(buf_cpy);
			free(buf);
			malloc_error();
		}
		i++;
		token = strtok(NULL, delim);
	}
	gvar->argv[i] = NULL;

	free(buf_cpy);
	return (gvar->argv);
}
