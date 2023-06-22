#include "monty.h"
monty info;

/**
 * main - entry point
 *@argc: number of argument
 *@argv: array of argument
 *
 *Return: success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (get_opcode(argv, &stack) == EXIT_FAILURE)
	{
		free_stack(&stack);
		return (EXIT_FAILURE);
	}
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
