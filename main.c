#include "monty.h"
int mode = 1;

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

	get_opcode(argv, &stack);
	return (EXIT_SUCCESS);
}
