/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** Displays one by one the characters of a string
*/

#include <unistd.h>
#include "my.h"

void my_putchar5(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar5(*str);
        str++;
    }
    return 0;
}
