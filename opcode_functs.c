#include "monty.h"

/**
 * op_divide - Func divides the second top element by the top element.
 * @stack: A double pointer.
 * @line_number:A  line number of the instruct in the monty file.
 */
void op_divide(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: Can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: Division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n /= (*stack)->n;
   st_pop(stack, line_number);
}

/**
 * op_mul - multiplies the second top element by the top element.
 * @stack: A double pointer to the top.
 * @line_number: A line number of the instruct. monty file.
 */
void op_mul(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: Can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n *= (*stack)->n;
    st_pop(stack, line_number);
}

/**
 * op_mod - Func comp. the remainder of the divi of the sec top elem by
 *        the top element.
 * @stack: A double pointer.
 * @line_number:A line number of the instruct in the monty file.
 */
void op_mod(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: Can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: Division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n %= (*stack)->n;
    st_pop(stack, line_number);
}

/**
 * op_comments - does nothing .
 * @stack: A double pointer.
 * @line_number: A line number of the instruction in the Monty file.
 */
void op_comments(stack_t **stack, unsigned int line_number) {
    (void)stack; 
    (void)line_number;
}
