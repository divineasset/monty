#include "monty.h"

/**
 * f_push - pushes a node to a stack
 * @stack: head of the stack
 *@n: line number
 */
void f_push(stack_t **stack, unsigned int n)
{
	stack_t *node = NULL;
	(void) n;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack)

		exit(EXIT_FAILURE);
	}

	node->prev = node->next = NULL;

	if (!(*stack))
		(*stack) = node;
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
}

/**
 * f_pall - prints a stack
 * @stack: pointer to a stack_t
 * @n: line number
 */
void f_pall(stack_t **stack, unsigned int n)
{
	stack_t *node, *head;
	(void) n;

	if (!stack || !(*stack))
		return;
	node = head = *stack;

	while (node)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}

/**
 * f_swap - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @line_number: line number
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	int store = 0;

	if ((stack == NULL) || (*stack == NULL) || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	store = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = store;
}

/**
 * f_add - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @line_number: line number
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) + ((*stack)->n);
	f_pop(stack, line_number);
}

/**
 * f_sub - swaps the data in two nodes
 * @stack: pointer to a stack_t
 * @line_number: line number
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) - ((*stack)->n);
	f_pop(stack, line_number);
}

