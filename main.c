#include "monty.h"
/**
* main - Monty code interp
* @argc: Number of argumts
* @argv: Monty file loc
* Return: return 0 success
*/
int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    stack_t *stack_ = NULL;
    char *line_ = NULL;
    size_t len_ = 0;
    ssize_t read_;
    int line_number_ = 1, i = 0;
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

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }	
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while ((read_ = getline(&line_, &len_, file)) != -1) {
        char *tok = strtok(line_, " \t\n");
        if (!tok || tok[0] == '#') continue;

        for (i = 0; instructions[i].opcode; i++) {
            if (strcmp(instructions[i].opcode, tok) == 0) {
                instructions[i].f(&stack_, line_number_);
                break;
            }
            if (!instructions[i + 1].opcode) {
                fprintf(stderr, "L%d:unkwn instruct %s\n", line_number_, tok);
                fclose(file);
                free(line_);
                free_stack(&stack_);
                return EXIT_FAILURE;
            }
        }
        line_number_++;
    }
    fclose(file);
    free(line_);
    free_stack(&stack_);
    return EXIT_SUCCESS;
}
