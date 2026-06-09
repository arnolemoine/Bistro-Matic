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

    for (; parser->expr[parser->pos] == '+' || parser->expr[parser->pos] == '-'; parser->pos++)
        if (parser->expr[parser->pos] == '-')
            sign *= -1;
    if (parser->expr[parser->pos] == '(') {
        
    } else {
        num = num_parser(parser);
    }
    num.sign = sign;
    return num;
}

char **parser(parser_t *parser)
{
    num_t num = num_parser(parser);

    return NULL;
}
