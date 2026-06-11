/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** compute_mul
*/

#include "bistromatic.h"
#include "my.h"

void compute_multiplication(char *num1, char *num2, char *res, int *lengths)
{
    int sum = 0;
    int pos1 = 0;
    int pos2 = 0;

    for (int i = lengths[0] - 1; i >= 0; i--) {
        for (int j = lengths[1] - 1; j >= 0; j--) {
            pos1 = i + j;
            pos2 = i + j + 1;
            sum = (num1[i] - '0') * (num2[j] - '0') + (res[pos2] - '0');
            res[pos2] = (sum % 10) + '0';
            res[pos1] = ((res[pos1] - '0') + (sum / 10)) + '0';
        }
    }
}
