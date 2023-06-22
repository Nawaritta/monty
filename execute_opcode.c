#include "monty.h"

int get_opcode(char **argv, stack_t **stack);
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
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

	info.code_file = fopen(argv[1], "r");
	info.opcode = NULL;

	if (info.code_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&info.opcode, &n, info.code_file) != -1)
	{
		info.opcode = strtok(info.opcode, " \t\n");

		if (info.opcode != NULL)
		{
			if (*info.opcode != '#')
			{
				if (execute_opcode(info.opcode, stack, line_number) == -1)
					return (EXIT_FAILURE);
			}
		}
		line_number++;
	}
	free_stack(stack);
	return (EXIT_SUCCESS);
}


/**
 * execute_opcode - executes the lines code
 *@opcode: the code to be executed
 *@stack: pointer to the top node
 *@line_number: the instruction line number
 *Return: 0 if the instruction is found and -1 otherwise
 */
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
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
			return (0);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (-1);
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
