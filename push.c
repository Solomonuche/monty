#include "monty.h"

/**
 * push - a function that pushes and integer unto a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	create_node(&newnode, line_number);

	if (*stack == NULL)
	{
		*stack = gvar->top = newnode;
	}
	else
	{

		newnode->prev = gvar->top;
		gvar->top->next = newnode;
		gvar->top = newnode;
	}
}
