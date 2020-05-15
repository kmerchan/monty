#include "monty.h"
/**
  * pchar_func - print top of stack as an ascii character
  * @stack: pointer to top of stack
  * @line_number: line number
  */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			fclose(global.fd);
			free(global.opcode);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
