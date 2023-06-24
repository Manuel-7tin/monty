#include "monty.h"

stack_t *stack = NULL;

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
	char *cmd_lin[10], *strtemp;
	int str_count = 0, data;
	stack_t *temp;

	strtemp = strtok(cmd, " ");
	while (strtemp)
	{
		cmd_lin[str_count++] = strtemp;
		strtemp = strtok(NULL, " ");
	}
	if (str_count != 2 || (strcmp(cmd_lin[1], "0") != 0 && atoi(cmd_lin[1]) == 0))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(cmd_lin[1]);

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
	/*free(temp);*/
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

/**
 * pint_stack - shows the top element of a stack
 *
 * @line_number: the line number of the command
 *
 * Return: void
 */

void pint_stack(int line_number)
{
	if (stack  == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", stack->n);
}
/**
 * pop - removes the top of the stack
 * @stack: global variable stack
 * @line_number: line number to pop
 * Return: Nothing
 */
void pop(unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	stack = stack->next;
	if (stack != NULL)
		stack->prev = NULL;
	free_stack();
}
