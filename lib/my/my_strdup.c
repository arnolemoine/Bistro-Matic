/*
** EPITECH PROJECT, 2025
** STRDUP
** File description:
** STRDUP
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(const char *str)
{
    int len = 0;
    char *dup = NULL;

    if (!str)
        return NULL;
    len = my_strlen(str);
    dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return dup;
}
