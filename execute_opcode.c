#include "monty.h"

int get_opcode(char **argv, stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void mode1(stack_t **stack, unsigned int line_number);
void mode2(stack_t **stack, unsigned int line_number);


/**
 * get_opcode - reads the code lines and parse it into instructions
 * @argv: array of the arguments passed into main
 * @stack: double pointer to the top of the stack
 */

int get_opcode(char **argv, stack_t **stack)
{
	char *opcode = NULL;
	size_t n = 0;
	int line_number = 1;

	FILE *code_file = fopen(argv[1], "r");


	if (code_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	      	return (EXIT_FAILURE);
	}

	while (getline(&opcode, &n, code_file) != -1)
	{

		opcode = strtok(opcode, " \t\n");

		if (opcode != NULL)
		{
			if (*opcode != '#')
				execute_opcode(opcode, stack, line_number);
		}
		line_number++;
	}
	free(opcode);
	free_stack(stack);
	fclose(code_file);
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

	mode = 1;
	
}


/**
 * mode1 - swichs to mode 2 (queue mode)
 * @stack: double pointer to the top of the stack
 * @line_number: instruction line number
 */
void mode2(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	mode = 2;

	
}

