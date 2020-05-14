#include "monty.h"

/**
 * free_for_exit_malloc - function to free all open/malloced before exit
 * due to malloc failure
 * @stack: input pointer to current stack
 */

void free_for_exit_malloc(stack_t *stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	fclose(global.fd);
	free(global.opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_for_exit_push - function to free all open/malloced before exit
 * due to push not having correct argument
 * @line_number: input current line number for error message
 * @stack: input pointer to current stack
 */

void free_for_exit_push(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(global.fd);
	free(global.opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_for_exit_error - function to free all open/malloced before exit
 * for generic error
 * @stack: input pointer to current stack
 */

void free_for_exit_error(stack_t *stack)
{
	fclose(global.fd);
	free(global.opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
