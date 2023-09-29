#include "monty.h"

/**
 * isInteger - a function that checks if a string is an integer
 * @str: input string
 *
 * Return: (True or False)
 */

int isInteger(char *str)
{
	int i;

	if (str[0] == '\0' || (str[0] == '-' && str[1] == '\0'))
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			continue;
		}

		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * create_node - a function that creates a linked list for monty operations
 * @newnode: pointer to newnode
 * @line_number: line number
 */

void create_node(stack_t **newnode, unsigned int line_number)
{

	*newnode = malloc(sizeof(stack_t));
	if (*newnode == NULL)
	{
		free_gvar();
		malloc_error();
	}

	if (gvar->argc < 1 || !isInteger(gvar->argv[1]))
	{
		fprintf(stderr, "L%d: usage: push integer ", line_number);
		free(*newnode);
		free_gvar();
		exit(EXIT_FAILURE);
	}

	(*newnode)->n = atoi(gvar->argv[1]);
	(*newnode)->prev = NULL;
	(*newnode)->next = NULL;

}
