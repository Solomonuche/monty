#include "monty.h"

/**
 * intialize_var - a function that initialise global variables
 *
 */

void intialize_var(void)
{
	gvar = malloc(sizeof(globa_v));
	if (gvar == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	gvar->argc = 0;
	gvar->stack = NULL;
	gvar->argv = NULL;
}
