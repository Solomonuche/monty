#include "monty.h"
/**
 * mod_ops - a function that dividion remainder of 2nd top element by
 * the top element of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void mod_ops(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;


	if ((*stack)->next == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = gvar->top;

	if (gvar->top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = temp->prev->n % temp->n;
	temp->prev->n = result;
	temp->prev->next = NULL;
	gvar->top = temp->prev;
	free(temp);
}
