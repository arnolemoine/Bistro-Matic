/*
** EPITECH PROJECT, 2026
** Bistro-Matic
** File description:
** convert_base
*/

#include "bistromatic.h"
#include "my.h"

char *convert_to_base_str(char *res, char const *base)
{
    char *buf = my_strdup(res);
    int i = 0;

    if (!buf)
        exit(84);
    if (buf[0] == '-')
        i++;
    while (buf[i] != '\0') {
        buf[i] = base[buf[i] - '0'];
        i++;
    }
    return buf;
}
