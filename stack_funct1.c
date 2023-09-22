#include "monty.h"

/**
 * st_push - func pushes an element .
 * @stack:  A double pointer to the top .
 * @line_number: A line number of the instrct in the monty file.
 */
void st_push(stack_t **stack, unsigned int line_number) {
    char *tok;
    int val;
    stack_t *new_node = malloc(sizeof(stack_t));

    tok = strtok(NULL, " \t\n");
    if (tok == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    val = atoi(tok);

    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = val;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * st_pall - func prints all values .
 * @stack: A double pointer.
 * @line_number: A line number of the instruct. in the monty file.
 */
void st_pall(stack_t **stack, unsigned int line_number) {
    stack_t *cur = *stack;
    (void)line_number; 

    while (cur != NULL) {
        printf("%d\n", cur->n);
        cur = cur->next;
    }
}

/**
 * st_pint - func prints the value top of stack.
 * @stack: A double pointer .
 * @line_number: A line no of the instruct in the monty file.
 */
void st_pint(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * st_pop - func removes the top element.
 * @stack: A double pointer .
 * @line_number: A line number .
 */
void st_pop(stack_t **stack, unsigned int line_number) {
    stack_t *temp_ = *stack;
    if (*stack == NULL) {
        fprintf(stderr, "L%d:  can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
   }
    *stack = (*stack)->next;
    free(temp_);
}

/**
 * st_swap - This swaps the top two elements.
 * @stack: A double pointer.
 * @line_number: A line number of the instruction.
 */
void st_swap(stack_t **stack, unsigned int line_number) {
    int temp = (*stack)->n;
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
