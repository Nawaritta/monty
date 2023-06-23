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
	char c;

	if (*stack == NULL || stack == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (is_ascii((*stack)->n))
	{
		c = (char)(*stack)->n;
		write(1, &c, 1);
		write(1, "\n", 1);
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
	stack_t *tmp = *stack;
	char c;

	(void) line_number;

	if (stack != NULL && *stack != NULL)
	{
		while (tmp != NULL && tmp->n != 0 && is_ascii(tmp->n))
		{
			c = (char)tmp->n;
			write(1, &c, 1);
			tmp = tmp->next;
		}
	}
	write(1, "\n", 1);
}
