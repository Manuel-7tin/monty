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
