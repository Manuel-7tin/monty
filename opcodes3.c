#include "monty.h"
/**
 * nop - does nothing
 * @line_number: number of command
 * Return: Nothing
 */
void nop(unsigned int line_number)
{
	(void)line_number;
}
/**
 * pchar - prints the char at the top
 * @line_number: line number of cmd
 * Return: void
 */
void pchar(unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if (stack->n < 0 || stack->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", stack->n);
}
/**
 * pstr - prints the string starting at the top
 * @line_number: line of cmd
 * Return: void
 */
void pstr(unsigned int line_number)
{
	(void)line_number;

	while(stack != NULL && stack->n != 0 && stack->n >= 0 && stack->n <= 127)
	{
		printf("%c", stack->);
		stack = stack->next;
	}
	printf("\n");
}
