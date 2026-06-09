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
        int l_digit = (i < left_len) ? (left->digits[i] - '0') : 0;
        int r_digit = (i < right_len) ? (right->digits[i] - '0') : 0;
        int sum = l_digit + r_digit + carry;
        carry = sum / 10;
        buf[i] = (sum % 10) + '0';
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
