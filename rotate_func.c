#include "monty.h"

/**
 * rotl_func - function to rotate the stack so the top element becomes the last
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack), *mover = (*stack);

	(void)line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	mover = mover->next;
	mover->prev = NULL;
	(*stack) = mover;
	while (mover->next != NULL)
		mover = mover->next;
	mover->next = holder;
	holder->prev = mover;
	holder->next = NULL;
}

/**
 * rotr_func - function to rotate the stack so the last element becomes the top
 * @stack: input pointer to head of stack
 * @line_number: line count currently reading instructions from
 */

void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *holder = (*stack), *mover = (*stack);

	(void)line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	while (holder->next != NULL)
		holder = holder->next;
	holder->prev->next = NULL;
	mover->prev = holder;
	holder->next = mover;
	holder->prev = NULL;
	(*stack) = holder;
}
