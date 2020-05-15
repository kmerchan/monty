#include "monty.h"
/**
  * pop_func - delete note at top of stack
  * @stack: pointer to head of stack
  * @line_number: line number
  */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack);

	if (*stack)
	{
		(*stack) = (*stack)->next;
		free(tmp);
		if (*stack)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
