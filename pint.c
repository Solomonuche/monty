#include "monty.h"
/**
 * pint - a function that displays top contents of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_gvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", gvar->top->n);
}
