#include "monty.h"

/**
 * free_for_exit_malloc - function to free all open/malloced before exit
 * due to malloc failure
 * @fd: input pointer to open file
 * @opcode: input pointer to malloced string containing opcode
 * @stack: input pointer to current stack
 */

void free_for_exit_malloc(FILE *fd, char *opcode, stack_t *stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	fclose(fd);
	free(opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_for_exit_push - function to free all open/malloced before exit
 * due to push not having correct argument
 * @line_number: input current line number for error message
 * @fd: input pointer to open file
 * @opcode: input pointer to malloced string containing opcode
 * @stack: input pointer to current stack
 */

void free_for_exit_push(unsigned int line_number, FILE *fd,
			char *opcode, stack_t *stack)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_for_exit_error - function to free all open/malloced before exit
 * for generic error
 * @fd: input pointer to open file
 * @opcode: input pointer to malloced string containing opcode
 * @stack: input pointer to current stack
 */

void free_for_exit_error(FILE *fd, char *opcode, stack_t *stack)
{
	fclose(fd);
	free(opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
