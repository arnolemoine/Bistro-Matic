/*
** EPITECH PROJECT, 2026
** check base
** File description:
** check base
*/

#include "my.h"
#include "bistromatic.h"

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}
