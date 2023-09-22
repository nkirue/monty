#include "monty.h"

/**
 * op_add - This adds the top two elements.
 * @stack: A double pointer.
 * @line_number: A line number of the instruct. in the monty file.
 */
void op_add(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n += (*stack)->n;
   st_pop(stack, line_number);
}

/**
 * op_nop -Func doesn't do anything.
 * @stack: A double pointer.
 * @line_number: A line number of the instruct. in the monty file.
 */
void op_nop(stack_t **stack, unsigned int line_number) {
    (void)stack; 
    (void)line_number;
}

/**
 * op_sub - Func subtracts the top element from the second top elements.
 * @stack: A double pointer.
 * @line_number: A line number of the instruct in the monty file.
 */
void op_sub(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n -= (*stack)->n;
    st_pop(stack, line_number);
}

/**
 * free_stack - Func that frees entire stack.
 * @stack: A double pointer.
 */
void free_stack(stack_t **stack) {
    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}
