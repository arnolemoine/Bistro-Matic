/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** compute_sub
*/

#include "bistromatic.h"
#include "my.h"

void compute_subtraction(char *n1, char *n2, char *result, int *lengths)
{
    int idxs[2] = {lengths[0] - 1, lengths[1] - 1};
    int borrow = 0;
    int res_idx = 0;

    while (idxs[0] >= 0) {
        result[res_idx] = get_sub_val(n1, n2, idxs, &borrow) + '0';
        res_idx++;
        idxs[0]--;
        idxs[1]--;
    }
    result[res_idx] = '\0';
}
