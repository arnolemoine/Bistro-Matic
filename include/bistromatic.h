/*
** EPITECH PROJECT, 2026
** BISTROMATIC
** File description:
** BISTROMATIC_H
*/

#ifndef BISTROMATIC_H
    #define BISTROMATIC_H
    #define OP_OPEN_PARENT_IDX 0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX 2
    #define OP_SUB_IDX 3
    #define OP_NEG_IDX 3
    #define OP_MULT_IDX 4
    #define OP_DIV_IDX 5
    #define OP_MOD_IDX 6

    #define EXIT_USAGE 84
    #define EXIT_BASE 84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC 84
    #define EXIT_READ 84
    #define EXIT_OPS 84

    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"

// expressions
char *eval_expr(char const *base, char const *ops,
    char const *expr, unsigned int size);
// checks & helper
void check_ops(char const *ops);
void check_base(char const *b);
int helper(void);
// infinite_add
char *infin_add(char *num1, char *num2);
void compute_addition(char *num1, char *num2, char *result, int *lengths);
// translate_expr
void translate_expr(char *expr, char const *b, char const *ops);
int get_idx(char c, char const *str);
// conversion
char *convert_to_base_str(char *res, char const *base);

#endif
