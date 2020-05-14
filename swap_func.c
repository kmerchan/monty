#include "monty.h"

/**
 * swap_func - function to swap the top two integers on the stack
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	int holder;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		fclose(global.fd);
		free(global.opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	holder = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = holder;
}
