#include "monty.h"
/**
  * addnode - add node to head of list
  * @head: head
  * @opcode: opcode and value
  * @linenum: line number
  *
  * Return: pointer to head
  */
stack_t *addnode(char *str, stack_t **head, int linenum)
{
	stack_t *newnode;
	char *contents;
	int i, n;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	contents = malloc(sizeof(char) * strlen(str));
	for (i = 0; str[i + 5] != '\0'; i++)
	{
		if (isdigit(str[i + 5]) != 0)
			contents[i] = str[i + 5];
		else
		{
			printf("L%d: unknown instruction %s\n", linenum, str);
			return (NULL);
		}
	}
	n = atoi(contents);
	free(contents);
	newnode->n = n;
	newnode->prev = NULL;
	if ((*head) == NULL)
	{
		(*head) = newnode;
		newnode->next = NULL;
	}
	else
	{
		newnode->next = (*head);
		(*head)->prev = newnode;
		(*head) = newnode;
	}
	return (*head);
}
