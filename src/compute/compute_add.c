/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** compute_add
*/

#include "bistromatic.h"
#include "my.h"

void compute_addition(char *num1, char *num2, char *result, int *lengths)
{
    int idx1 = lengths[0] - 1;
    int idx2 = lengths[1] - 1;
    int carry = 0;
    int res_idx = 0;
    int digit1 = 0;
    int digit2 = 0;

    while (idx1 >= 0 || idx2 >= 0 || carry > 0) {
        digit1 = (idx1 >= 0) ? num1[idx1] - '0' : 0;
        digit2 = (idx2 >= 0) ? num2[idx2] - '0' : 0;
        result[res_idx] = ((digit1 + digit2 + carry) % 10) + '0';
        carry = (digit1 + digit2 + carry) / 10;
        idx1--;
        idx2--;
        res_idx++;
    }
    result[res_idx] = '\0';
}
