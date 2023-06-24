#include "monty.h"

/**
 * run_opcodes - runs the given opcodes
 *
 * @cmds: The commands to be run by opcodes
 *
 * Return: 0on success
 */

int run_opcodes(char **cmds)
{
	char *temp, *hold;
	int line_number = 1, i;

	i = line_number;
	while (strcmp(cmds[i-1], "NULL") != 0)
	{
		printf("line %i in cmd is %s\n", i, cmds[i-1]);
		i++;
	}
	hold = malloc(100 * sizeof(char));
	while (strcmp(cmds[line_number - 1], "NULL") != 0)
	{
		strcpy(hold, cmds[line_number - 1]);
		printf("hold is %s\n", hold);
		temp = strtok(hold, " ");
		if (strcmp(temp, "push") == 0)
			push_stack(cmds[line_number - 1], line_number);
		else if (strcmp(temp, "pall") == 0)
			pall_stack();
		else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, temp);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(hold);
	return (0);
}
