#include "monty.h"

/**
 * mul_func - function to multiply the top two integers on the stack
 * and save as new top value of stack
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		fclose(global.fd);
		free(global.opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	holder = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->n *= (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(holder);
}
