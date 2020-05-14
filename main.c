#include "monty.h"

/**
 * main - function to interpret and execute Monty ByteCode file
 * @argc: count of number of input arguments from command line
 * @argv: input array of arguments, including program name
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	char *str, *str_check, *opcode;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	fd = opening_func(argc, argv);
	while (1)
	{
		str_check = malloc(sizeof(char) * 1024);
		if (str_check == NULL)
			free_for_exit_malloc(fd, NULL, stack);
		str = fgets(str_check, 1024, fd);
		if (str == NULL)
		{
			free(str_check);
			break;
		}
		opcode = getopcode(&str);
		if (opcode == NULL)
			free_for_exit_malloc(fd, opcode, stack);
		/* printf("opcode: |%s|", opcode);*/
		if (strncmp(opcode, "push ", 5) == 0)
		{
			stack = addnode(opcode, &stack, line_number);
			if (stack == NULL)
				free_for_exit_error(fd, opcode, stack);
		}
		else if (strcmp(opcode, "push") == 0)
			free_for_exit_push(line_number, fd, opcode, stack);
		else
		{
			stack = findinstruction(opcode, &stack, line_number);
			if (stack == NULL)
				free_for_exit_error(fd, opcode, stack);
		}
		free(opcode);
		line_number++;
	}
	fclose(fd);
	free_stack(stack);
	return (0);
}

/**
 * open_function - checks if given correct parameters to open file
 * @argc: count of input arguments from command line
 * @argv: input 2D array of arguments, including program name
 * Return: fd if file was opened successfully, NULL otherwise
 */

FILE *opening_func(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
