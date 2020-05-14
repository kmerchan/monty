#include "monty.h"
/**
  * findinstruction - find opcode instruction
  * @opcode: opcode
  * @stack: head of stack
  * @line_number: line number
  *
  * Return: pointer to head of stack
  */
stack_t *findinstruction(char *opcode, stack_t **stack,
			 unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {

		{"pall", pall_func}, {"pint", pint_func}, {"swap", swap_func},
		{"add", add_func}, {"\n", nop_func}, {"nop", nop_func},
		{"sub", sub_func}, {"mul", mul_func}, {"pop", pop_func},
		{"div", div_func}, {"mod", mod_func}, {"pchar", pchar_func},
		{"pstr", pstr_func}, {NULL, NULL} };


	if (opcode[0] == '#')
		return (*stack);
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			break;
	}
	if (instructions[i].opcode == NULL)
	{
		printf("L:%d: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		return (NULL);
	}
	instructions[i].f(stack, line_number);
	return (*stack);
}
