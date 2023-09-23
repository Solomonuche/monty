#include "monty.h"
/**
 * pall - a function that displays contents of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *temp;

	if (*stack == NULL)
		return;

	temp = gvar->top;
	
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
