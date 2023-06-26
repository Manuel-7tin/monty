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
	int line_number = 1;

	if (cmds == NULL)
		exit(EXIT_FAILURE);
	hold = malloc(100 * sizeof(char));
	if (hold == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (strcmp(cmds[line_number - 1], "NULL") != 0)
	{
		strcpy(hold, cmds[line_number - 1]);
		temp = strtok(hold, " ");
		if (strcmp(temp, "push") == 0)
			push_stack(cmds[line_number - 1], line_number);
		else if (strcmp(temp, "pall") == 0)
			pall_stack();
		else if (strcmp(temp, "pint") == 0)
			pint_stack(line_number);
		else if (strcmp(temp, "pop") == 0)
			pop(line_number);
		else if (strcmp(temp, "swap") == 0)
			swap(line_number);
		else if (strcmp(temp, "add") == 0)
			add(line_number);
		else if (strcmp(temp, "nop") == 0)
			nop(line_number);
		else if (strcmp(temp, "sub") == 0)
			sub(line_number);
		else if (strcmp(temp, "mul") == 0)
			mul(line_number);
		else if (strcmp(temp, "div") == 0)
			divde(line_number);
		else if (strcmp(temp, "mod") == 0)
			mod(line_number);
		else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, temp);
			exit(EXIT_FAILURE);
		}
		if (temp[0] == '#')
			continue;
		line_number++;
	}
	free(hold);
	return (0);
}

/**
 * free_stack - frees all space allocated for the stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *temp_stack;

	while (stack != NULL)
	{
		temp_stack = stack->next;
		free(stack);
		stack = temp_stack;
	}
}
