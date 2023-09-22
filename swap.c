#include "monty.h"
/**
 * swap - a function that swaps two top contents of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int data;


	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	while (temp->next != 0)
	{
		temp = temp->next;
	}
	data = temp->n;
	temp->n = temp->prev->n;
	temp->prev->n = data;
}
