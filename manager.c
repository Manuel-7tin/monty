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
	char *temp;
	int line_number = 1;

	while (strcmp(cmds[line_number], "NULL") != 0)
	{
		temp = strtok(cmds[line_number - 1], " ");
		if (strcmp(temp, "push") == 0)
			push_stack(cmds[line_number - 1], line_number);
		else if (strcmp(temp, "pall") == 0)
			pall_stack();
		else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, temp);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
