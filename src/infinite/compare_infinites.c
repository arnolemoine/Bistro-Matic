/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** compare_infinites
*/

#include "bistromatic.h"
#include "my.h"

int compare_infinite(char *num1, char *num2)
{
    int len1 = my_strlen(num1);
    int len2 = my_strlen(num2);

    if (len1 != len2)
        return len1 - len2;
    return my_strcmp(num1, num2);
}
