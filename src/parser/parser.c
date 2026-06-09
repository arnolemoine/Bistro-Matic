/*
** EPITECH PROJECT, 2026
** parser
** File description:
** parser
*/

#include "my.h"
#include "bistromatic.h"

num_t num_parser(parser_t *parser)
{
    int start = parser->pos;
    num_t num;

    while (is_base_char(parser->expr[parser->pos], parser->base))
        parser->pos++;
    num.digits = my_strndup(parser->expr + start, parser->pos - start);
    return num;
}

num_t factor_parser(parser_t *parser)
{
    int sign = 1;
    num_t num;

    while (parser->expr[parser->pos] == '+' ||
        parser->expr[parser->pos] == '-') {
        if (parser->expr[parser->pos] == '-')
            sign *= -1;
        parser->pos++;
    }
    if (parser->expr[parser->pos] == '(') {
        parser->pos++;
        num = expr_parser(parser);
        if (parser->expr[parser->pos] != ')') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
        parser->pos++;
    } else
        num = num_parser(parser);
    num.sign = sign;
    return num;
}

num_t term_parser(parser_t *parser)
{
    num_t num = factor_parser(parser);
    char o = 0;

    while (parser->expr[parser->pos] == '*' || parser->expr[parser->pos]
        == '/' || parser->expr[parser->pos] == '%') {
        o = parser->expr[parser->pos];
        parser->pos++;
        if (o == '*')
            printf("multiplication\n");
        if (o == '/')
            printf("division\n");
        if (o == '%')
            printf("modulo\n");
        num_t right = factor_parser(parser);
        num = right;
    }
    return num;
}

num_t expr_parser(parser_t *parser)
{
    num_t num = term_parser(parser);
    num_t right;
    char op = 0;

    while (parser->expr[parser->pos] == '+' ||
        parser->expr[parser->pos] == '-') {
        op = parser->expr[parser->pos];
        parser->pos++;
        right = term_parser(parser);
        if (op == '+')
        if (op == '-')
        num = right;
    }
    return num;
}
