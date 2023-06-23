#include "monty.h"

void printeger(int number);
void free_stack(stack_t **stack);
int is_ascii(int c);


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

	if (info.code_file != NULL)
		fclose(info.code_file);

	if (info.opcode != NULL)
		free(info.opcode);

	if (stack && *stack != NULL)
	{
		while ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
			free((*stack)->prev);

		}
		free(*stack);
		stack = NULL;
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

/**
 * is_integer - checks if a string is an integer
 *@opcode: the string to go though
 *Return: 1 if it is an integer and 0 otherwise
 */
int is_integer(char *opcode)
{
	int i = 0;

	if (opcode != NULL)
	{
		if (opcode[i] == '-')
		{
			if (opcode[++i] == '\0')
				return (0);
		}

		while (opcode[i] != '\0')
		{
			if (isdigit(opcode[i]))
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
