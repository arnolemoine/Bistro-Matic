/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** my_revstr
*/

#include "my.h"

void my_revstr(char *str)
{
    int length = my_strlen(str);
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
