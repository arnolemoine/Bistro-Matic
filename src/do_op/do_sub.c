/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** do_sub
*/

#include "bistromatic.h"
#include "my.h"

char *do_sub(char *n1, char *n2, int s1, int s2)
{
    if (s1 == 1 && s2 == 1)
        return infin_sub(n1, n2);
    if (s1 == -1 && s2 == -1)
        return infin_sub(n2, n1);
    if (s1 == 1 && s2 == -1)
        return infin_add(n1, n2);
    return apply_sign(infin_add(n1, n2), -1);
}
