#include "monty.h"
/**
  * addnode - add node to head of list
  * @stack: head
  * @opcode: opcode push and value
  * @line_number: line number
  *
  * Return: pointer to head
  */
stack_t *addnode(char *opcode, stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	char contents[1024];
	int i, n;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	for (i = 0; opcode[i + 5] != '\0'; i++)
	{
		if (_isdigit(opcode[i + 5]) != 0)
			contents[i] = opcode[i + 5];
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			return (NULL);
		}
	}
	contents[i] = '\0';
	n = atoi(contents);
	newnode->n = n;
	newnode->prev = NULL;
	if ((*stack) == NULL)
	{
		newnode->next = NULL;
		(*stack) = newnode;
	}
	else
	{
		newnode->next = (*stack);
		(*stack)->prev = newnode;
		(*stack) = newnode;
	}
	return (*stack);
}
