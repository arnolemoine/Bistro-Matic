/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <signal.h>
    #include <fcntl.h>
    #define ERROR 84
    #define BUF_SIZE 100000

void my_putchar(char c);
int my_putstr(char const *str);
void my_revstr(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int get_nb_r(char *str);
char *my_recover_nbr(int nb);
char **str_to_word_array(char *av, char *delimiter);
int my_getnbr(const char *str);

#endif /* !MY_H_ */
