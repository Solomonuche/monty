#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_s - global varibales to be acessed by diff source files
 * @argc: argument count
 * @stack: points to stack
 * @argv: argument vecotor
 *
 *
 */

typedef struct globa_s
{
	int argc;
	stack_t *stack;
	char **argv;
	stack_t *top;
} globa_v;

extern globa_v *gvar;

/**
extern stack_t *stack;
extern char **argv;
extern int argc;
*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char **parser(char *buf);
void interpret(char **tokens, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void create_node(stack_t **newnode, unsigned int line_number);
int isInteger(char *str);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_ops(stack_t **stack, unsigned int line_number);
void mul_ops(stack_t **stack, unsigned int line_number);
void mod_ops(stack_t **stack, unsigned int line_number);
void pchar_ops(stack_t **stack, unsigned int line_number);


void intialize_var(void);
void malloc_error(void);
void free_tokens(char **tokens);
void free_gvar(void);

#endif
