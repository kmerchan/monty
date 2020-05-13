#include "monty.h"

/**
 * free_stack - function to free all elements in the stack
 * @stack: input pointer to head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
