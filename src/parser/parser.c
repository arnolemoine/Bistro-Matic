/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** parser
*/

#include "my.h"
#include "bistromatic.h"

char *parse_parenthesis(char **str)
{
    char *res;

    (*str)++;
    res = parse_expr(str);
    if (**str == ')') {
        (*str)++;
    } else {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    return res;
}

char *parse_factor(char **str)
{
    int sign = 1;
    char *res;

    while (**str == '-' || **str == '+') {
        if (**str == '-')
            sign *= -1;
        (*str)++;
    }
    if (**str == '(')
        res = parse_parenthesis(str);
    else
        res = get_number(str);
    return apply_sign(res, sign);
}

char *parse_term(char **str)
{
    char *res = parse_factor(str);
    char *val;
    char *tmp;
    char op;

    while (**str == '*' || **str == '/' || **str == '%') {
        op = **str;
        (*str)++;
        val = parse_factor(str);
        check_zero_str(val, op);
        tmp = res;
        res = do_op(res, val, op);
        free(tmp);
        free(val);
    }
    return res;
}

char *parse_expr(char **str)
{
    char *res = parse_term(str);
    char *val;
    char *tmp;
    char op;

    while (**str == '+' || **str == '-') {
        op = **str;
        (*str)++;
        val = parse_term(str);
        tmp = res;
        res = do_op(res, val, op);
        free(tmp);
        free(val);
    }
    return res;
}
