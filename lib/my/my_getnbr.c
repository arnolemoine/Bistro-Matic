/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** get a nbr
*/
#include <stdio.h>
#include <limits.h>

int my_getnbr(const char *str)
{
    long result = 0;
    int sign = 1;

    while (*str && (*str < '0' || *str > '9')) {
        if (*str == '-')
            sign = -1;
        if (*str == '+')
            sign = 1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        if (result * sign > INT_MAX)
            return INT_MAX;
        if (result * sign < INT_MIN)
            return INT_MIN;
        str++;
    }
    return (int)(result * sign);
}
