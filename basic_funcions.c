#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);


/**
 * push - pushes an element to the stack.
 * @stack: double pointer to the top of the stack
 * @line_number:  the execution line number
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp = NULL;
	char *opcode = strtok(NULL, " \t\n");
	int arg;

	if (!is_integer(opcode))
	{
		free_stack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	arg = atoi(opcode);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	new_node->prev = NULL;

	if (*stack == NULL || stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
		return;
	}

	if (info.mode == 2) /* Queue mode */
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = NULL;
	}
	else    /* Stack mode */
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * pall - prints a stack
 *@stack: double pointer to the stack of the list
 * @line_number:  the execution line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	current = *stack;

	while (current != NULL)
	{
		printeger(current->n);
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}


/**
 * pint - Prints the last added node (the head)
 * @stack: double pointer to the head
 * @line_number: the execution line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL || stack == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printeger((*stack)->n);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * pop - deletes the last added node (the head)
 * @stack: double pointer to the head
 * @line_number: the execution line number
 */
void pop(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || stack == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
