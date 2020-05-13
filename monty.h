#ifndef MONTY_H
#define MONTY_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* STRUCTS AND DEFINITIONS */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* FUNCTION PROTOTYPES */
/* function to parse first opcode and needed arguments from line read */
char *getopcode(char **str);

/* function to add node to stack (push opcode) */
stack_t *addnode(char *opcode, stack_t **stack, unsigned int line_number);

/* function to match opcode to specific function */
stack_t *findinstruction(char *opcode, stack_t **stack,
			  unsigned int line_number);

/* function to print all elements of the stack */
void pall_func(stack_t **stack, unsigned int line_number);

/* function to free all elements of stack */
void free_stack(stack_t *stack);

#endif /* MONTY_H */
