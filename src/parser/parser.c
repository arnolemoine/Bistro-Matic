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

    while (is_base_char(EXPR_POS, parser->base))
        parser->pos++;
    num.digits = my_strndup(parser->expr + start, parser->pos - start);
    return num;
}

num_t factor_parser(parser_t *parser)
{
    num_t num;

    while (EXPR_POS == parser->ops[2] || EXPR_POS == parser->ops[3]) {
        if (EXPR_POS == parser->ops[3])
            num.sign *= -1;
        parser->pos++;
    }
    if (EXPR_POS == parser->ops[0]) {
        parser->pos++;
        num = expr_parser(parser);
        if (EXPR_POS != parser->ops[1]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
        parser->pos++;
    } else
        num = num_parser(parser);
    return num;
}

num_t term_parser(parser_t *parser)
{
    num_t num = factor_parser(parser);
    num_t right;
    char o = 0;

    while (EXPR_POS == parser->ops[4] || EXPR_POS
        == parser->ops[5] || EXPR_POS == parser->ops[6]) {
        o = EXPR_POS;
        parser->pos++;
        if (o == parser->ops[4])
            printf("multiplication\n");
        if (o == parser->ops[5])
            printf("division\n");
        if (o == parser->ops[6])
            printf("modulo\n");
        right = factor_parser(parser);
        num = right;
    }
    return num;
}

num_t expr_parser(parser_t *parser)
{
    num_t num = term_parser(parser);
    num_t right;
    char op = 0;

    while (EXPR_POS == parser->ops[2] || EXPR_POS == parser->ops[3]) {
        op = EXPR_POS;
        parser->pos++;
        right = term_parser(parser);
        if (op == parser->ops[2])
            num = addition(&num, &right);
        if (op == parser->ops[3])
            printf("sub\n");
    }
    return num;
}
