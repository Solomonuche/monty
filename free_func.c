#include "monty.h"

/**
 * malloc_error - a function that handles malloc failure
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - a functions that frees tokens
 * @tokens: tokens
 */

void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
 * free_gvar - a function that free all global variables
 */

void free_gvar(void)
{
	int i;
	stack_t *temp;

	if (gvar == NULL)
		return;

	if (gvar->stack)
	{
		while (gvar->stack != NULL)
		{
			temp = gvar->stack;
			gvar->stack = gvar->stack->next;
			free(temp);
		}
		free(gvar->stack);
		gvar->stack = NULL;
	}
	if (gvar->argv)
	{

		for (i = 0; i < gvar->argc; i++)
		{
			free(gvar->argv[i]);
			gvar->argv[i] = NULL;
		}
		free(gvar->argv);
		gvar->argv = NULL;
	}

	free(gvar);
	gvar = NULL;
}
