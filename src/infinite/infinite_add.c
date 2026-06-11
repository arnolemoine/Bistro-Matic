/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** infinite_add
*/

#include "bistromatic.h"
#include "my.h"

char *infin_add(char *num1, char *num2)
{
    int lengths[2] = {my_strlen(num1), my_strlen(num2)};
    int max_len = (lengths[0] > lengths[1]) ? lengths[0] : lengths[1];
    char *result = malloc(sizeof(char) * (max_len + 2));

    if (!result)
        exit(84);
    compute_addition(num1, num2, result, lengths);
    my_revstr(result);
    return result;
}
