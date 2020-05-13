#include "monty.h"

#define OPCODE_END (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')

/**
 * getopcode - function to get first opcode instruction from line
 * @str: input string containing one line of input file
 * Return: string containing just the single instruction, arguments
 */

char *getopcode(char *str)
{
	int i = 0, j = 0, end_check = 1;
	char *opcode = str;

	/* check to make sure code does not seg fault */
	if (str == NULL)
		return(NULL);
	/* move past leading whitespace */
	while (str[i] == ' ')
		i++;
	/* check to make sure code does not seg fault */
	if (str[i] == '\0')
		return(NULL);
	/* assign first instruction to opcode string */
	for (j = 0; OPCODE_END && j < 20; j++, i++)
		opcode[j] = str[i];
	if (str[i] == '\0')
		end_check = 0;
	opcode[j] = '\0';
	/* check if opcode accepts arguments */
	if (strcmp(opcode, "push") == 0 && end_check)
	{
		/* change null byte to space delimeter */
		opcode[j] = ' ';
		/* move past middle whitespace */
		while (str[i] == ' ')
			i++;
		/* check to make sure code does not seg fault */
		if (str[i] == '\0')
			return(opcode);
		for (j += 1; OPCODE_END; j++, i++)
			opcode[j] = str[i];
		opcode[j] = '\0';
	}
	return(opcode);
}
