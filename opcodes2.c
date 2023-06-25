#include "monty.h"
/**
 * add - adds fidt two elements in a stack
 * @line_number: line number
 * Return: Nothing
 */
void add(unsigned int line_number)
{
	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	stack->next->n += stack->n;
	pop(line_number);
}
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
 * sub - Substract the top from the second in a stack
 * @line_number: line numer of cmd
 * Return:void
 */
void sub(unsigned int line_number)
{
	int fi
	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	stack->next->n -= stack->n;
	pop(line_number);
}
