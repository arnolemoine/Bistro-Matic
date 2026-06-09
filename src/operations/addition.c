/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** addition
*/

#include "my.h"
#include "bistromatic.h"

static int fill_digits(num_t *left, num_t *right, char *buf, int max_len)
{
    int left_len = my_strlen(left->digits);
    int right_len = my_strlen(right->digits);
    int carry = 0;
    int i = 0;

    while (i < max_len || carry) {
        i++;
    }
    buf[i] = '\0';
    return i;
}

num_t addition(num_t *left, num_t *right)
{
    num_t res;
    int left_len = my_strlen(left->digits);
    int right_len = my_strlen(right->digits);
    int max_len = (left_len > right_len) ? left_len : right_len;

    res.digits = malloc(max_len + 2);
    if (!res.digits)
        return res;
    fill_digits(left, right, res.digits, max_len);
    res.sign = 1;
    return res;
}
