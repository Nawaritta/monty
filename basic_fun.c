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
	stack_t *new_node, *tmp;
	char *opcode = strtok(NULL, "\n \t");
	int arg, i = 0;

	while (opcode != NULL && opcode[i] != '\0')
	{
		if (!isdigit(opcode[i++]) && opcode[0] != '-')
		{
			i = -1;
			break;
		}
	} 
	
	if (opcode == NULL || i == -1)
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	arg = atoi(opcode);


	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->n = arg;
	new_node->prev = NULL;


	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
		return;
	}

	if(mode == 2)
	{
		printf("Queue mode\n");
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
	} else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * pall - prints a stack
 *@stack: double pointer to the stack of the list
 *
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
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

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop - deletes the last added node (the head)
 * @stack: double pointer to the head
 * @line_number: the execution line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		
		exit(EXIT_FAILURE);
	}
	tmp = *stack;

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	free(tmp);
}
