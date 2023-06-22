#include "monty.h"

/**
 * printeger - prints an integer to the stdout
 *@number: the integer to printeger
 *
*/
void printeger(int number)
{
	char buffer[20];
	int len = snprintf(buffer, sizeof(buffer), "%d", number);

	write(STDOUT_FILENO, buffer, len);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: pointer to the top node of the stack
 */
void free_stack(stack_t **stack)
{
	if (stack && *stack != NULL)
	{
		while ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
			free((*stack)->prev);

		}
		free(*stack);
	}
}

/**
 * is_ascii - Checks if a character is within the ASCII range.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is within the ASCII range, 0 otherwise.
 */
int is_ascii(int c)
{
	return (c >= 0 && c <= 127);
}
