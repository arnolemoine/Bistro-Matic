/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** my_revstr
*/

#include "my.h"

int my_strlength(char const *str)
{
    int length = 0;

    while (*str != '\0'){
        length++;
        str++;
    }
    return length;
}

char *my_revstr(char *str)
{
    int length_str = my_strlength(str);
    char *debut_str = str;
    char *fin_str = str + (length_str - 1);
    int acc;
    char c;

    if (length_str <= 1){
        return str;
    }
    if (length_str > 1){
        for (acc = 0; acc != length_str / 2; acc++){
            c = *debut_str;
            *debut_str = *fin_str;
            *fin_str = c;
            debut_str++;
            fin_str--;
        }
    }
    return str;
}
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
