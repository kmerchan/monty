#include "monty.h"

/**
 * nop_func - function to catch newline, empty line, or nop
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	free(global.opcode);
	global.opcode = malloc(sizeof(char) * 2);
	if (global.opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	global.opcode[0] = '\n';
	global.opcode[1] = '\0';
}
