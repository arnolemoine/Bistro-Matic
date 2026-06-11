/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** infinite_sub
*/

#include "bistromatic.h"
#include "my.h"

int get_sub_val(char *n1, char *n2, int *idxs, int *borrow)
{
    int sub_val = (n1[idxs[0]] - '0') - *borrow;

    if (idxs[1] >= 0)
        sub_val -= (n2[idxs[1]] - '0');
    if (sub_val < 0) {
        sub_val += 10;
        *borrow = 1;
    } else {
        *borrow = 0;
    }
    return sub_val;
}

char *infin_sub(char *num1, char *num2)
{
    int cmp = compare_infinite(num1, num2);
    int lengths[2] = {my_strlen(num1), my_strlen(num2)};
    char *result = malloc(sizeof(char) * (lengths[0] + 2));

    if (cmp < 0) {
        free(result);
        result = infin_sub(num2, num1);
        return apply_sign(result, -1);
    }
    compute_subtraction(num1, num2, result, lengths);
    my_revstr(result);
    return remove_leading_zeros(result);
}
