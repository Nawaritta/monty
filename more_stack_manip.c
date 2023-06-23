#include "monty.h"
#include <ctype.h>

void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to the top of the stack
 * @line_number:  the execution line number
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || stack == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (is_ascii((*stack)->n))
	{
		fprintf(stdout, "%c\n", (*stack)->n);
		return;
	}
	free_stack(stack);
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pstr -  prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number:  the execution line number
 *
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if (stack != NULL && *stack != NULL)
	{
		tmp = *stack;

		while (tmp != NULL && tmp->n != 0 && is_ascii(tmp->n))
		{
			fprintf(stdout, "%c", tmp->n);
			tmp = tmp->next;
		}
	}
	fprintf(stdout, "\n");
}
