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

typedef struct s_parser {
    const char *expr;
    int pos;
    char *base;
    char *ops;
} parser_t;

typedef struct s_num {
    char *digits;
    int sign;
} num_t;

char *eval_expr(char const *base, char const *ops,
    char const *expr, unsigned int size);
char *get_expr(unsigned int size);
void check_ops(char const *ops);
void check_base(char const *b);
int helper(void);
char **parser(parser_t *parser);

num_t expr_parser(parser_t *parser);
num_t term_parser(parser_t *parser);
num_t factor_parser(parser_t *parser);
num_t num_parser(parser_t *parser);

num_t addition(num_t *left, num_t *right);


#endif
