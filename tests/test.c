/*
** EPITECH PROJECT, 2026
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "bistromatic.h"

Test(calc, echo_pipe)
{
    FILE *fp;
    char buf[128] = {0};
    size_t n;

    fp = popen("echo -n 4+5+9+12+90 | ./calc 0123456789 \"()+-*%/\" 11", "r");
    cr_assert_not_null(fp);
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    pclose(fp);
    cr_assert_eq(n > 0, 1);
    cr_assert_str_eq(buf, "120");
}

Test(error_size, echo_pipe)
{
    FILE *fp;
    char buf[128] = {0};
    size_t n;

    fp = popen("echo -n 4+5+9+12+90 | ./calc 0123456789 \"()+-*%/\" 15", "r");
    cr_assert_not_null(fp);
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    pclose(fp);
    cr_assert_eq(n > 0, 1);
    cr_assert_str_eq(buf, "error");
}

Test(error_ops, echo_pipe)
{
    FILE *fp;
    char buf[128] = {0};
    size_t n;

    fp = popen("echo -n 4+5+9+12+90 | ./calc 0123456789 \"()+-A*%/\" 11", "r");
    cr_assert_not_null(fp);
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    pclose(fp);
    cr_assert_eq(n > 0, 1);
    cr_assert_str_eq(buf, "syntax error");
}

Test(error_base, echo_pipe)
{
    FILE *fp;
    char buf[128] = {0};
    size_t n;

    fp = popen("echo -n \"4+5+9+12+90\" | ./calc 0 \"()+-*%/\" 11", "r");
    cr_assert_not_null(fp);
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    pclose(fp);
    cr_assert_eq(n > 0, 1);
    cr_assert_str_eq(buf, "syntax error");
}

Test(addition, simple)
{
    num_t a = {.digits = strdup("123"), .sign = 1};
    num_t b = {.digits = strdup("77"), .sign = 1};
    num_t res = addition(&a, &b);

    cr_assert_str_eq(res.digits, "200");

    free(a.digits);
    free(b.digits);
    free(res.digits);
}

Test(addition, simple_add)
{
    num_t a = {.digits = strdup("123"), .sign = 1};
    num_t b = {.digits = strdup("77"), .sign = 1};
    num_t res = addition(&a, &b);

    cr_assert_str_eq(res.digits, "200");
    cr_assert_eq(res.sign, 1);

    free(a.digits);
    free(b.digits);
    free(res.digits);
}

Test(addition, carry_and_diff_length)
{
    num_t a = {.digits = strdup("999"), .sign = 1};
    num_t b = {.digits = strdup("1"), .sign = 1};
    num_t res = addition(&a, &b);

    cr_assert_str_eq(res.digits, "1000");
    cr_assert_eq(res.sign, 1);

    free(a.digits);
    free(b.digits);
    free(res.digits);
}