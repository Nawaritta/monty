#include "monty.h"

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void Div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/**
 * add - adds the top two elements of the stack
 *@stack: double pointer to the top of the stack
 *@line_number: the execution line number
*/
void add(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	(*stack)->n += (*stack)->prev->n;
	free((*stack)->prev);
}

/**
 * sub - subtracts the top two elements of the stack
 *@stack: double pointer to the top of the stack
 *@line_number: the execution line number
*/
void sub(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	(*stack)->n -= (*stack)->prev->n;
	free((*stack)->prev);
}


/**
 * Div - divides the 2nd top element of the stack by the topest
 *@stack: double pointer to the top of the stack
 *@line_number: the execution line number
*/
void Div(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->n /= (*stack)->prev->n;
	free((*stack)->prev);
}


/**
 * mul - multiplies the top two elements of the stack
 *@stack: double pointer to the top of the stack
 *@line_number: the execution line number
*/
void mul(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	(*stack)->n *= (*stack)->prev->n;
	free((*stack)->prev);
}

/**
 * mod - the second top element modulo the top element of the stack
 *@stack: double pointer to the top of the stack
 *@line_number: the execution line number
*/
void mod(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	(*stack)->n %= (*stack)->prev->n;
	free((*stack)->prev);
}
