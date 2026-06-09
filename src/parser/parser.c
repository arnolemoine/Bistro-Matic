/*
** EPITECH PROJECT, 2026
** parser
** File description:
** parser
*/

#include "my.h"
#include "bistromatic.h"

void parser_term(parser_t *parser, num_t *num)
{
    for(int i = parser->pos; parser->expr[i]; i++) {
        if (parser->expr[i] == "*" || parser->expr[i] == "/") {
            
        }
    }
}

char **parser(parser_t *parser)
{
    num_t num;

    for (; parser->expr[parser->pos]; parser->pos++) {
        if (parser->expr[parser->pos] == "-" || parser->expr[parser->pos] == "+")
            parser_term(parser, &num);
    }
    return NULL;
}
