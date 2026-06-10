/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** Displays the number of char in the str passed as parameter
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (*str != '\0'){
        len++;
        str++;
    }
    return len;
}
