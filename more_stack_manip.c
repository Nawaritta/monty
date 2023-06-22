#include "monty.h"
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
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	       	exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
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
	(void) line_number;

	if (stack != NULL && *stack != NULL)
	{
		while (tmp != NULL)
		{
			if (!isascii((tmp)->n))
				break;
			write(1, (char *)&(tmp->n), 1);
			tmp = tmp->next;
		}
	}
	write(1, "\n", 1);
}
