/*
** EPITECH PROJECT, 2026
** strtowordarray
** File description:
** my str to word array
*/

#include "my.h"

int in_delim(int i, char *av, char *delim)
{
    for (int y = 0; delim[y]; y++) {
        if (av[i] && av[i] == delim[y]) {
            return 1;
        }
    }
    return 0;
}

char **allocator_array(char *av, char *delimiter)
{
    char **array = NULL;
    int to_alloc = 1;
    int next_val = 0;
    int in_delimit = 0;

    for (int i = 0; av[i]; i++) {
        in_delimit = in_delim(i, av, delimiter);
        if (!in_delimit)
            next_val = 0;
        if (in_delimit && !next_val) {
            next_val = 1;
            to_alloc++;
        }
    }
    array = malloc(sizeof(char *) * (to_alloc + 1));
    if (!array)
        return NULL;
    return array;
}

int stwa_supply(char *av, int *len, int *i, char *delimiter)
{
    int start = *i;
    int found = 0;

    *len = 0;
    for (; av[*i];) {
        if (in_delim(*i, av, delimiter))
            found = 1;
        if (found)
            break;
        (*len)++;
        (*i)++;
    }
    return start;
}

char **str_to_word_array(char *av, char *delimiter)
{
    int i = 0;
    int index = 0;
    int start = 0;
    int len = 0;
    char **array = allocator_array(av, delimiter);

    while (av[i]) {
        if (in_delim(i, av, delimiter)) {
            i++;
            continue;
        }
        start = stwa_supply(av, &len, &i, delimiter);
        array[index] = malloc(len + 1);
        for (int j = 0; j < len; j++)
            array[index][j] = av[start + j];
        array[index][len] = '\0';
        index++;
    }
    array[index] = NULL;
    return array;
}
