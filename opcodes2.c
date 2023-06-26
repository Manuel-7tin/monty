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
	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	stack->next->n -= stack->n;
	pop(line_number);
}
/**
 * mul - Multiplies the second top element of a stack with the top
 * @line_number: number of cmd
 * Return: void
 */
void mul(unsigned int line_number)
{
	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	stack->next->n *= stack->n;
	pop(line_number);
}

/**
 * divde - Divides top stack elment
 *
 * @line_number: The line number of that command in the file
 *
 * Return: void
 */

void divde(unsigned int line_number)
{
	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (stack->n == 0)
	{
		fprintf(stderr, "L%i: division by zero", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	stack->next->n /= stack->n;
	pop(line_number);
}
