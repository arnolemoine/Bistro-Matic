/*
** EPITECH PROJECT, 2025
** putchar
** File description:
** putxchr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
