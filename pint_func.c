#include "monty.h"

/**
 * pint_func - function to print integer from top of stack
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void pint_func(stack_t **stack, unsigned int line_number)
{

	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
