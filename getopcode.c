#include "monty.h"

#define OPCODE_END ((*str)[i] != ' ' && (*str)[i] != '\n' && (*str)[i] != '\0')

/**
 * getopcode - function to get first opcode instruction from line
 * @str: pointer to input string containing one line of input file
 * Return: string containing just the single instruction, arguments
 */

char *getopcode(char **str)
{
	int i = 0, j = 0, end_check = 1;
	char *opcode;

	opcode = malloc(sizeof(char) * (strlen(*str) + 1));
	if (opcode == NULL)
	{
		free(*str), *str = NULL;
		return (NULL);
	}
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == '\0' || (*str)[i] == '\n')
	{
		free(*str), *str = NULL;
		opcode[j] = '\n';
		opcode[j + 1] = '\0';
		return (opcode);
	}
	for (j = 0; OPCODE_END; j++, i++)
		opcode[j] = (*str)[i];
	if ((*str)[i] == '\0')
		end_check = 0;
	opcode[j] = '\0';
	if (strcmp(opcode, "push") == 0 && end_check)
	{
		opcode[j] = ' ';
		while ((*str)[i] == ' ')
			i++;
		if ((*str)[i] == '\0' || (*str)[i] == '\n')
		{
			free(*str), *str = NULL;
			opcode[j] = '\0';
			return (opcode);
		}
		for (j += 1; OPCODE_END; j++, i++)
			opcode[j] = (*str)[i];
		opcode[j] = '\0';
	}
	free(*str), *str = NULL;
	return (opcode);
}
