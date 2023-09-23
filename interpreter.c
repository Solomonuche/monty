#include "monty.h"

/**
 * interpret - a function that perform specific operations based on opcodes
 * @tokens: arguments array
 * @line_number: line number of the executing argument
 *
 * Return: (nothing)
 */

void interpret(char **tokens, unsigned int line_number)
{
	int j;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_ops},
		{"mul", mul_ops},
		{"mod", mod_ops},
		{"#", nop},
		{NULL, NULL}
	};


	for (j = 0; ops[j].opcode != NULL; j++)
	{
		if (strcmp(tokens[0], ops[j].opcode) == 0)
		{
			ops[j].f(&gvar->stack, line_number);
			free_tokens(tokens);
			return;
		}
	}


	fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, tokens[0]);

	free_tokens(tokens);
	exit(EXIT_FAILURE);
}
