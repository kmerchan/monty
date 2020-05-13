#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	char *str;
	int linenum = 1;
	stack_t *head = NULL;
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
		str = getopcode(str);
		if (strncmp(str, "push ", 5) == 0)
			head = addnode(str, &head, linenum);
			if (head == NULL)
				/* free stuff */
				exit(EXIT_FAILURE);
		else
			head = findinstruction(str, &head, linenum);
		linenum++;
	}
	return (0);
}
