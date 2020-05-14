#include "monty.h"
/**
  * pstr_func - print stack as ascii characters
  * @stack: pointer to top of stack
  * @line_number: line number
  */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack);

	(void)line_number;

	if (mover)
	{
		while (mover)
		{
			if ((mover)->n > 0 && (mover)->n <= 127)
			{
				printf("%c", (mover)->n);
				mover = mover->next;
			}
			else
				break;
		}
	}
	printf("\n");
}
