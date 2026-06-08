/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** Copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        a = i;
    }
    dest[a + 1] = '\0';
    return dest;
}
