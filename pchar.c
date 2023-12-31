#include "monty.h"
/**
 * pchar_ops - a function that prints char two top of a stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: (nothing)
 */

void pchar_ops(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (gvar->top->n >= 0 && gvar->top->n <= 127)
	{
		putchar(gvar->top->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	}
}
