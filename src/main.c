/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Bistromatic project, to make a calculator
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "my.h"

char *eval_expr(char const *base, char const *ops,
    char const *expr, unsigned int size)
{
    parser_t pars;
    num_t num;

    pars.base = (char *)base;
    pars.expr = (char *)expr;
    pars.ops = (char *)ops;
    pars.pos = 0;
    num = expr_parser(&pars);
    if (pars.expr[pars.pos] != '\0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    return num.digits;
}

char *get_expr(unsigned int size)
{
    char *expr = NULL;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    unsigned int size = 0;
    char *expr = NULL;

    if (ac == 2 && my_strcmp(av[0], "-h")) {
        helper();
        return 0;
    }
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    eval_expr(av[1], av[2], expr, size);
    return (EXIT_SUCCESS);
}
