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
	stack_t *temp;


	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	/*
	 * while (temp->next != 0)
	 * {
	 *	temp = temp->next;
	 * }
	 */
	printf("%d\n", temp->n);
}
