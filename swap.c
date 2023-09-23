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
	int data;


	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = gvar->top->n;
	gvar->top->n = gvar->top->prev->n;
	gvar->top->prev->n = data;
}
