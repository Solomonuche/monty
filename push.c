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
	stack_t *newnode, *temp;

	create_node(&newnode, line_number);

	if (*stack == NULL)
	{
		*stack = newnode;
	}
	else
	{
		temp = *stack;

		while (temp->next != 0)
		{
			temp = temp->next;
		}
		newnode->prev = temp;
		temp->next = newnode;
	}
}
