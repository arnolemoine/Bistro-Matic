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

    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

// core
char *eval_expr(char const *b, char const *ops, char const *e, unsigned int s);
void translate_expr(char *expr, char const *b, char const *ops);
char *convert_to_base_str(char *res, char const *base);
// parser
char *parse_expr(char **str);
char *parse_term(char **str);
char *parse_factor(char **str);
// compute
void compute_addition(char *num1, char *num2, char *result, int *lengths);
void compute_multiplication(char *num1, char *num2, char *res, int *lengths);
void compute_subtraction(char *n1, char *n2, char *result, int *lengths);
// do_op
char *do_add(char *n1, char *n2, int s1, int s2);
char *do_op(char *s1, char *s2, char op);
char *do_sub(char *n1, char *n2, int s1, int s2);
// infinite
char *infin_add(char *num1, char *num2);
char *infin_sub(char *num1, char *num2);
char *infin_mult(char *num1, char *num2);
// infinite_utils
int get_sub_val(char *n1, char *n2, int *idxs, int *borrow);
int compare_infinite(char *num1, char *num2);
char *remove_leading_zeros(char *str);
// checks & helper
int helper(void);
void check_base(char const *b);
void check_ops(char const *ops);
// utils
char *get_number(char **str);
char *apply_sign(char *s, int sign);
void check_zero_str(char *val, char op);

#endif
