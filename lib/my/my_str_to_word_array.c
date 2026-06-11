/*
** EPITECH PROJECT, 2026
** strtowordarray
** File description:
** my str to word array
*/

#include "my.h"

int is_delim(int i, char *av, char *delim)
{
    for (int y = 0; delim[y]; y++) {
        if (av[i] && av[i] == delim[y]) {
            return 1;
        }
    }
    return 0;
}

char **allocate_array(char *av, char *delim)
{
    char **array = NULL;
    int to_alloc = 1;
    int next_val = 0;
    int is_delimiter = 0;

    for (int i = 0; av[i]; i++) {
        is_delimiter = is_delim(i, av, delim);
        if (!is_delimiter)
            next_val = 0;
        if (is_delimiter && !next_val) {
            next_val = 1;
            to_alloc++;
        }
    }
    array = malloc(sizeof(char *) * (to_alloc + 1));
    if (!array)
        return NULL;
    return array;
}

int stwa_supply(char *av, int *len, int *i, char *delim)
{
    int start = *i;
    int found = 0;

    *len = 0;
    for (; av[*i];) {
        if (is_delim(*i, av, delim))
            found = 1;
        if (found)
            break;
        (*len)++;
        (*i)++;
    }
    return start;
}

char **str_to_word_array(char *av, char *delim)
{
    int i = 0;
    int index = 0;
    int start = 0;
    int len = 0;
    char **array = allocate_array(av, delim);

    while (av[i]) {
        if (is_delim(i, av, delim)) {
            i++;
            continue;
        }
        start = stwa_supply(av, &len, &i, delim);
        array[index] = malloc(len + 1);
        for (int j = 0; j < len; j++)
            array[index][j] = av[start + j];
        array[index][len] = '\0';
        index++;
    }
    array[index] = NULL;
    return array;
}
