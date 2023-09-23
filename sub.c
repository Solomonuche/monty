#include "monty.h"
/**
 * sub - a function that subtrack two top contents of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;


	if ((*stack)->next == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = gvar->top;

	result = temp->prev->n - temp->n;
	temp->prev->n = result;
	temp->prev->next = NULL;
	gvar->top = temp->prev;
	free(temp);
}
