/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** infinite_utils
*/

#include "bistromatic.h"
#include "my.h"

char *remove_leading_zeros(char *str)
{
    int i = 0;
    char *cleaned_str;

    while (str[i] == '0' && str[i + 1] != '\0')
        i++;
    if (i == 0)
        return str;
    cleaned_str = my_strdup(str + i);
    free(str);
    return cleaned_str;
}
