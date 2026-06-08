/*
** EPITECH PROJECT, 2025
** get_nb_r
** File description:
** get the number
*/

#include "my.h"

int get_nb_r(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}
