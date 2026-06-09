/*
** EPITECH PROJECT, 2026
** Une_petite_biere-BTTF
** File description:
** helper
*/

#include "my.h"
#include "bistromatic.h"

int helper(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n");
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses and the");
    my_putstr(" 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return 0;
}
