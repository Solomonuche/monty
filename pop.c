#include "monty.h"
/**
 * pop - a function that deletes top contents of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;


	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);

}
