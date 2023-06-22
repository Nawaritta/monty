#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
	int data;
	struct stack_node *prev;
	struct stack_node *next;
} stack_t;

void free_stack(stack_t **stack);

int main() {
	// Create a sample linked list for demonstration purposes
	stack_t *node1 = malloc(sizeof(stack_t));
	stack_t *node2 = malloc(sizeof(stack_t));
	stack_t *node3 = malloc(sizeof(stack_t));

	node1->data = 1;
	node1->prev = NULL;
	node1->next = node2;

	node2->data = 2;
	node2->prev = node1;
	node2->next = node3;

	node3->data = 3;
	node3->prev = node2;
	node3->next = NULL;

	// Assign the top node to the stack pointer
	stack_t *stack = node1;

	// Free the linked list using the free_stack function
	free_stack(&stack);

	// Check if the stack pointer is NULL after freeing
	if (stack == NULL) {
		printf("Linked list freed successfully.\n");
	} else {
		printf("Linked list freeing failed.\n");
	}

	return 0;
}

void free_stack(stack_t **stack) {


	if (stack && *stack != NULL)
	{
		while ((*stack)->next != NULL) {
			*stack = (*stack)->next;
			free((*stack)->prev);
		}
		free(*stack);
		//stack = NULL;
	}
}
