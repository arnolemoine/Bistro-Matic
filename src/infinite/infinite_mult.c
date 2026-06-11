/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** infinite_mult
*/

#include "bistromatic.h"
#include "my.h"

void init_mult_result(char *result, int total_length)
{
    for (int i = 0; i < total_length; i++)
        result[i] = '0';
    result[total_length] = '\0';
}

char *infin_mult(char *num1, char *num2)
{
    int lengths[2] = {my_strlen(num1), my_strlen(num2)};
    int total_length = lengths[0] + lengths[1];
    char *result = malloc(sizeof(char) * (total_length + 1));

    if (!result)
        exit(84);
    init_mult_result(result, total_length);
    compute_multiplication(num1, num2, result, lengths);
    return remove_leading_zeros(result);
}
