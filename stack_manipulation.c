#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**
 * rotl - rotates the stack to the top.
 * @stack: double pointer to the top of the stack
 * @line_number:  the execution line number
 *
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;

	if (tmp->next == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: double pointer to the top of the stack
 * @line_number:  the execution line number
 *
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
		return;

	if (tmp->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;

	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the execution line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = i;
}
