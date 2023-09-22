#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* Stack-related functions */
void st_push(stack_t **stack, unsigned int line_number);
void st_pall(stack_t **stack, unsigned int line_number);
void st_pint(stack_t **stack, unsigned int line_number);
void st_pop(stack_t **stack, unsigned int line_number);
void st_swap(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
/* Below are the opcode functions implemented */
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_divide(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_comments(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
