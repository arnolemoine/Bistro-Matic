/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** copy a number n of char
*/

int my_strleng(char const *str)
{
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++){
        if (i > my_strleng(src)){
            dest[i] = '\0';
        }
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
