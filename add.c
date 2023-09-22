#include "monty.h"
/**
 * add - a function that adds two top contents of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;


	if ((*stack)->next == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	while (temp->next != 0)
	{
		temp = temp->next;
	}
	result = temp->prev->n + temp->n;
	temp->prev->n = result;
	temp->prev->next = NULL;
	free(temp);
}
