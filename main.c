#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	char *str, *str_check, *opcode;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

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
	while (1)
	{
		str_check = malloc(sizeof(char) * 1024);
		if (str_check == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(fd);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		str = fgets(str_check, 1024, fd);
		if (str == NULL)
		{
			free(str_check);
			free_stack(stack);
			break;
		}
		opcode = getopcode(&str);
		/* ADD NULL CHECK */
		/*printf("opcode: %s on line: %u\n", opcode, line_number);*/
		if (strncmp(opcode, "push ", 5) == 0)
		{
			stack = addnode(opcode, &stack, line_number);
			if (stack == NULL)
			{
				fclose(fd);
				free(opcode);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "push") == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			fclose(fd);
			free(opcode);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		else
			stack = findinstruction(opcode, &stack, line_number);
		free(opcode);
		line_number++;
	}
	fclose(fd);
	free_stack(stack);
	return (0);
}
