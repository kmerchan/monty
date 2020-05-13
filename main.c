#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	char *str;
	int linenum = 1;
	char opcode[16];
	stack_t *head;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	str = malloc(sizeof(char) * 1024);
	while (str != NULL)
	{
		str = fgets(str, 1024, fd);
		if (str == NULL)
			continue;
		opcode = getopcode(str);
/*		if (opcode == push)
			head = addnode(opcode, head, linenum);
		else
			head = findinstruction(opcode, head, linenum);
*/		linenum++;
	}
	return (0);
}
