/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** Displays one by one the characters of a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str++;
    }
    return 0;
}
