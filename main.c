#include "monty.h"

variable_t global;

/**
 * main - function to interpret and execute Monty ByteCode file
 * @argc: count of number of input arguments from command line
 * @argv: input array of arguments, including program name
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	char *str = NULL;
	size_t buffsize;
	ssize_t check;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	global.fd = opening_func(argc, argv);
	while (1)
	{
		check = getline(&str, &buffsize, global.fd);
		if (check == -1)
		{
			free(str);
			break;
		}
		global.opcode = getopcode(&str);
		if (global.opcode == NULL)
			free_for_exit_malloc(stack);
		if (strncmp(global.opcode, "push ", 5) == 0)
		{
			stack = addnode(global.opcode, &stack, line_number);
			if (stack == NULL)
				free_for_exit_error(stack);
		}
		else if (strcmp(global.opcode, "push") == 0)
			free_for_exit_push(line_number, stack);
		else
		{
			stack = findinstruction(global.opcode,
						&stack, line_number);
		}
		free(global.opcode);
		line_number++;
	}
	fclose(global.fd);
	free_stack(stack);
	return (0);
}

/**
 * open_function - checks if given correct parameters to open file
 * @argc: count of input arguments from command line
 * @argv: input 2D array of arguments, including program name
 * Return: pointer to open file
 */

FILE *opening_func(int argc, char *argv[])
{
	int status;

	global.opcode = NULL;
	global.fd = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	status = open(argv[1], O_RDONLY);
	if (status == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global.fd = fdopen(status, "r");
	if (global.fd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (global.fd);
}
