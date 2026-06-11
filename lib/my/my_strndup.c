/*
** EPITECH PROJECT, 2025
** STRNDUP
** File description:
** STRNDUP
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strndup(const char *str, int n)
{
    char *dup = NULL;

    if (!str)
        return NULL;
    dup = malloc(n + 1);
    if (!dup)
        return NULL;
    for (int i = 0; i < n; i++)
        dup[i] = str[i];
    dup[n] = '\0';
    return dup;
}
