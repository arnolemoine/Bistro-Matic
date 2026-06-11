/*
** EPITECH PROJECT, 2026
** check ops
** File description:
** check ops
*/

#include "my.h"
#include "bistromatic.h"

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}
