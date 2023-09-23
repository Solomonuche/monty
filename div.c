#include "monty.h"
/**
 * div_ops - a function that divides 2nd top element by
 * the top element of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void div_ops(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;


	if ((*stack)->next == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = gvar->top;

	if (gvar->top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = temp->prev->n / temp->n;
	temp->prev->n = result;
	temp->prev->next = NULL;
	gvar->top = temp->prev;
	free(temp);
}
