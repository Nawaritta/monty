#include "monty.h"

int get_opcode(char **argv, stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void mode1(stack_t **stack, unsigned int line_number);
void mode2(stack_t **stack, unsigned int line_number);


/**
 * get_opcode - reads the code lines and parse it into instructions
 * @argv: array of the arguments passed into main
 * @stack: double pointer to the top of the stack
 * Return: 0  or 1
 */

int get_opcode(char **argv, stack_t **stack)
{
	size_t n = 0;
	int line_number = 1;
	char *opcode = NULL;

	info.code_file = fopen(argv[1], "r");
	info.opcode = NULL;

	if (info.code_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&info.opcode, &n, info.code_file) != -1)
	{
		opcode = strtok(info.opcode, " \t\n");

		if (opcode != NULL)
		{
			if (*opcode != '#')
				execute_opcode(opcode, stack, line_number);
			else
				free(opcode);
		}
		line_number++;
	}
	return (EXIT_SUCCESS);
}


/**
 * execute_opcode - executes the lines code
 *@opcode: the code to be executed
 *@stack: pointer to the top node
 *@line_number: the instruction line number
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{

	instruction_t instructions[] = {

		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"rotl", rotl},
		{"rotr", rotr},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", Div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"queue", mode1},
		{"stack", mode2},
		{"nop", NULL}
	};


	int i, instructions_number = sizeof(instructions) / sizeof(instruction_t);


	for (i = 0; i < instructions_number; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (instructions[i].f != NULL)
				instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}



/**
 * mode1 - swichs to mode 1 (stack mode)
 * @stack: double pointer to the top of the stack
 * @line_number: instruction line number
 */
void mode1(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	info.mode = 1;

}


/**
 * mode2 - swichs to mode 2 (queue mode)
 * @stack: double pointer to the top of the stack
 * @line_number: instruction line number
 */
void mode2(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	info.mode = 2;

}
