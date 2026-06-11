/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** do_op
*/

#include "bistromatic.h"
#include "my.h"

char *do_op(char *s1, char *s2, char op)
{
    int s1_s = (s1[0] == '-') ? -1 : 1;
    int s2_s = (s2[0] == '-') ? -1 : 1;
    char *n1 = (s1_s == -1) ? s1 + 1 : s1;
    char *n2 = (s2_s == -1) ? s2 + 1 : s2;
    char *res;

    if (op == '+')
        return do_add(n1, n2, s1_s, s2_s);
    if (op == '-')
        return do_sub(n1, n2, s1_s, s2_s);
    res = infin_mult(n1, n2);
    return apply_sign(res, s1_s * s2_s);
}
