/*
** EPITECH PROJECT, 2025
** sqss
** File description:
** dsqdsq
*/

#include "my.h"
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s1[i] - s2[i] == 0)
        i++;
    return s1[i] - s2[i];
}
