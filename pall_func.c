#include "monty.h"

/**
 * pall_func - function to print all elements of stack
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack);

	(void)line_number;

	while (mover)
	{
		printf("%d\n", mover->n);
		mover = mover->next;
	}
}
