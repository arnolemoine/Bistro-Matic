/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** copy a number n of char
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++){
        if (i > my_strlen(src)){
            dest[i] = '\0';
        }
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
