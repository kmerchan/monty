#ifndef MONTY_H
#define MONTY_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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

/**
 * struct variable_s - opcode string and file pointer fd
 * @opcode: the opcode string
 * @fd: file pointer
 *
 * Description: struct to hold opcode and file pointer
 * as global variable to be able to free all variables
 */
typedef struct variable_s
{
	char *opcode;
	FILE *fd;
} variable_t;

/* FUNCTION PROTOTYPES AND GLOBAL VARIABLE*/
extern variable_t global;

/* function to check initial conditions and open the file */
FILE *opening_func(int argc, char *argv[]);

/* function to parse first opcode and needed arguments from line read */
char *getopcode(char **str);

/* function to add node to stack (push opcode) */
stack_t *addnode(char *opcode, stack_t **stack, unsigned int line_number);

/* function to match opcode to specific function */
stack_t *findinstruction(char *opcode, stack_t **stack,
			 unsigned int line_number);

/* function to print all elements of the stack */
void pall_func(stack_t **stack, unsigned int line_number);

/* function to print integer at top of stack */
void pint_func(stack_t **stack, unsigned int line_number);

/* function to swap the top two integers on the stack */
void swap_func(stack_t **stack, unsigned int line_number);

/* function to add the top two integers on the stack & replace the top value*/
void add_func(stack_t **stack, unsigned int line_number);

/* function to delete top of stack */
void pop_func(stack_t **stack, unsigned int line_number);

/* function to subtract top two integers on the stack & replace the top value*/
void sub_func(stack_t **stack, unsigned int line_number);

/* function to multiply top two integers on the stack & replace the top value*/
void mul_func(stack_t **stack, unsigned int line_number);

/* function to divide top two integers on the stack & replace the top value*/
void div_func(stack_t **stack, unsigned int line_number);

/* function to modulo top two integers on the stack & replace the top value*/
void mod_func(stack_t **stack, unsigned int line_number);

/* function to print top of stack as ascii character */
void pchar_func(stack_t **stack, unsigned int line_number);

/* function to print stack as string */
void pstr_func(stack_t **stack, unsigned int line_number);

/* function to rotate stack so the top element becomes the last */
void rotl_func(stack_t **stack, unsigned int line_number);

/* function to rotate stack so the last element becomes the top */
void rotr_func(stack_t **stack, unsigned int line_number);

/* function to catch empty lines or newlines from invalid command */
void nop_func(stack_t **stack, unsigned int line_number);

/* function to free all elements of stack */
void free_stack(stack_t *stack);

/* function to print error message, free everything, & exit if push arg fails*/
void free_for_exit_push(unsigned int line_number, stack_t *stack);

/* function to print error message, free everything, & exit if malloc fails */
void free_for_exit_malloc(stack_t *stack);

/* function to print free everything & exit for general error */
void free_for_exit_error(stack_t *stack);

/* function to check if char is digit */
int _isdigit(int c);

#endif /* MONTY_H */
