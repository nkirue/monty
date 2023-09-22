#include "monty.h"

/* define the instruct set with correspond funct */
instruction_t instructions[] = {
    {"push", st_push},
    {"pall", st_pall},
    {"pint", st_pint},
    {"pop", st_pop},
    {"swap", st_swap},
    {"add", op_add},
    {"nop", op_nop},
    {"sub", op_sub},
    {"div", op_divide},
    {"mul", op_mul},
    {"mod", op_mod},
    {"#", op_comments}, 
    {NULL, NULL}
};
