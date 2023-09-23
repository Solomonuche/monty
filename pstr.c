#include "monty.h"
/**
 * pstr_ops - a function that prints char two top of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void pstr_ops(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = gvar->top;

	(void) line_number;

	if ((*stack) == NULL)
	{
		putchar('\n');
		return;
	}

	while (temp != NULL)
	{
		if (temp->n >= 0 && temp->n <= 127)
		{
			if (temp->n == 0)
				break;
			putchar(temp->n);
		}
		temp = temp->prev;
	}
	putchar('\n');
}
