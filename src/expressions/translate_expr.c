/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** translate_expr
*/

#include "bistromatic.h"
#include "my.h"

int get_idx(char c, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

void translate_expr(char *expr, char const *b, char const *ops)
{
    char std_ops[] = "()+-*/%";
    int idx = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        idx = get_idx(expr[i], ops);
        if (idx != -1) {
            expr[i] = std_ops[idx];
            continue;
        }
        idx = get_idx(expr[i], b);
        if (idx != -1)
            expr[i] = idx + '0';
    }
}
