/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** eval_expr
*/

#include "bistromatic.h"
#include "my.h"

char *eval_expr(char const *base, char const *ops,
    char const *expr, unsigned int size)
{
    char *std_expr = my_strdup(expr);
    char *ptr = std_expr;
    char *final_res = NULL;
    char *str_res = NULL;

    translate_expr(std_expr, base, ops);
    final_res = parse_expr(&ptr);
    if (*ptr != '\0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    str_res = convert_to_base_str(final_res, base);
    free(std_expr);
    free(final_res);
    return str_res;
}
