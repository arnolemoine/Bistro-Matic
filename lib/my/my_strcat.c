/*
** EPITECH PROJECT, 2025
** strcat
** File description:
** strcat
*/

int my_strlen1(char const *str)
{
    int length = 0;

    while (*str != '\0'){
        length++;
        str++;
    }
    return length;
}

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen1(dest);
    int i = 0;

    for (i = 0; i < src[i] != '\0'; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return dest;
}
