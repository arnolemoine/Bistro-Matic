/*
** EPITECH PROJECT, 2025
** recover_nb
** File description:
** recover a number , to cast it into a str
*/

#include <unistd.h>
#include "my.h"

int get_digits(int nb)
{
    int cpt = 1;

    while (nb >= 10) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}

char *my_recover_nbr(int nb)
{
    int len = get_digits(nb);
    char *buffer = malloc(sizeof(char) * len + 1);
    int i = len - 1;

    buffer[len] = '\0';
    while (i >= 0) {
        buffer[i] = ('0' + (nb % 10));
        nb = nb / 10;
        i--;
    }
    return buffer;
}
