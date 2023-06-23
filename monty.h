#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


/* ------------- Structures ---------------*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct monty_byte_code - structure holding basic info about the code
 * @code_file: file holding the bytcode
 * @mode: code execution mode (stack or queue)
 * @opcode: opcode extracted from the code file
 */
typedef struct monty_byte_code
{
	FILE *code_file;
	int mode;
	char *opcode;
} monty;

extern monty info;


/*-----------------/ execute_opcode.c /--------------*/

int get_opcode(char **argv, stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void mode1(stack_t **stack, unsigned int line_number);
void mode2(stack_t **stack, unsigned int line_number);


 /*----------------/  basic_fun.c /-----------------*/

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);


 /*---------------/  manipulations_functions.c /------------*/

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);



 /*----------------/ operations_fun /--------------*/

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void Div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);


 /*----------------/ more_stack_manip /--------------*/

void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);


/*----------------/ helpers   --------------*/

void printeger(int number);
int is_ascii(int c);
void free_stack(stack_t **stack);
#endif
