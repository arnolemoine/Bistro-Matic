/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** parser_utils
*/

#include "bistromatic.h"
#include "my.h"
#include <stdlib.h>

void check_zero_str(char *val, char op)
{
    if ((op == '/' || op == '%') && val[0] == '0' && val[1] == '\0') {
        my_putstr(ERROR_MSG);
        exit(84);
    }
}

char *get_number(char **str)
{
    int len = 0;
    char *res;

    while ((*str)[len] >= '0' && (*str)[len] <= '9')
        len++;
    if (len == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    res = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        res[i] = (*str)[i];
    res[len] = '\0';
    *str += len;
    return res;
}

char *apply_sign(char *str, int sign)
{
    char *res;

    if (sign == 1 || (str[0] == '0' && str[1] == '\0'))
        return str;
    if (str[0] == '-') {
        res = my_strdup(str + 1);
        free(str);
        return res;
    }
    res = malloc(my_strlen(str) + 2);
    res[0] = '-';
    my_strcpy(res + 1, str);
    free(str);
    return res;
}
