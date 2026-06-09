/*
** EPITECH PROJECT, 2026
** isbase char
** File description:
** is base char
*/

#include "my.h"

int is_base_char(char c, char *base)
{
    int i = 0;

    while (base[i]) {
        if (base[i] == c)
            return 1;
        i++;
    }
    return 0;
}