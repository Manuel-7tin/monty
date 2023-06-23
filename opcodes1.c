#include "monty.h"

/**
 * push_stack - pushes to the stack
 *
 * @cmd: The command passed in
 * @line_number: The line number of that command in the file
 *
 * Return: void
 */

void push_stack(char *cmd, int line_number)
{
	char *cmd_split[10], *strtemp;
	int str_count = 0, data;
	stack_t *temp;

	strtemp = strtok(cmd, " ");
	while (strtemp)
	{
		cmd_split[str_count++] = strtemp;
		strtemp = strtok(NULL, " ");
	}
	if (str_count != 2 || (strcmp(cmd_split[1], '0') == 0 && atoi(cmd_split[1]) == 0))
	{
		fprintf(stderr, "L%i: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(cmd_split[1]);

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		temp->n = data;
		temp->next = NULL;
		temp->prev = NULL;
		stack = temp;
	} else
	{
		temp->n = data;
		temp->next = stack;
		temp->prev = NULL;
		stack->prev = temp;
		stack = temp;
	}
}

/**
 * pall_stack - displays all elemts in the stack
 *
 * Return: void
 */

void pall_stack(void)
{
	stack_t *temp;

	temp = stack;
	if (temp == NULL)
		exit(EXIT_SUCCESS);
	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
