/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** tests unitaires et fonctionnels
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "bistromatic.h"
#include "my.h"

Test(addition, simple)
{
    cr_redirect_stdout();
    system("echo \"12+42\" | ./calc 0123456789 \"()+-*/%\" 5");
    cr_assert_stdout_eq_str("54");
}

Test(addition, zero)
{
    cr_redirect_stdout();
    system("echo \"0+0\" | ./calc 0123456789 \"()+-*/%\" 3");
    cr_assert_stdout_eq_str("0");
}

Test(subtraction, simple)
{
    cr_redirect_stdout();
    system("echo \"42-10\" | ./calc 0123456789 \"()+-*/%\" 5");
    cr_assert_stdout_eq_str("32");
}

Test(subtraction, same_values)
{
    cr_redirect_stdout();
    system("echo \"5-5\" | ./calc 0123456789 \"()+-*/%\" 3");
    cr_assert_stdout_eq_str("0");
}

Test(subtraction, result_negative)
{
    cr_redirect_stdout();
    system("echo \"3-10\" | ./calc 0123456789 \"()+-*/%\" 4");
    cr_assert_stdout_eq_str("-7");
}

Test(multiplication, simple)
{
    cr_redirect_stdout();
    system("echo \"6*7\" | ./calc 0123456789 \"()+-*/%\" 3");
    cr_assert_stdout_eq_str("42");
}

Test(multiplication, by_zero)
{
    cr_redirect_stdout();
    system("echo \"99*0\" | ./calc 0123456789 \"()+-*/%\" 4");
    cr_assert_stdout_eq_str("0");
}

Test(parentheses, basic)
{
    cr_redirect_stdout();
    system("echo \"(2+3)*4\" | ./calc 0123456789 \"()+-*/%\" 7");
    cr_assert_stdout_eq_str("20");
}

Test(priority, mul_before_add)
{
    cr_redirect_stdout();
    system("echo \"2+3*4\" | ./calc 0123456789 \"()+-*/%\" 5");
    cr_assert_stdout_eq_str("14");
}

Test(unary, negative)
{
    cr_redirect_stdout();
    system("echo \"-5+3\" | ./calc 0123456789 \"()+-*/%\" 4");
    cr_assert_stdout_eq_str("-2");
}

Test(flag_h, exit_zero)
{
    int ret = system("./calc -h");

    cr_assert_eq(WEXITSTATUS(ret), 0);
}

Test(args, no_args)
{
    int ret = system("./calc");

    cr_assert_eq(WEXITSTATUS(ret), 84);
}

Test(args, base_too_short)
{
    int ret = system("echo \"1+1\" | ./calc 0 \"()+-*/%\" 3");

    cr_assert_eq(WEXITSTATUS(ret), 84);
}

Test(args, ops_wrong_length)
{
    int ret = system("echo \"1+1\" | ./calc 01 \"()+-*\" 3");

    cr_assert_eq(WEXITSTATUS(ret), 84);
}

Test(compare_infinite, equal, .init = cr_redirect_stdout)
{
    cr_assert_eq(compare_infinite("42", "42"), 0);
}

Test(remove_leading_zeros, with_zeros, .init = cr_redirect_stdout)
{
    char *s = my_strdup("007");
    char *res = remove_leading_zeros(s);

    cr_assert_str_eq(res, "7");
    free(res);
}

Test(remove_leading_zeros, no_zeros, .init = cr_redirect_stdout)
{
    char *s = my_strdup("42");
    char *res = remove_leading_zeros(s);

    cr_assert_str_eq(res, "42");
    free(res);
}

Test(infin_add, simple, .init = cr_redirect_stdout)
{
    char *res = infin_add("12", "30");

    cr_assert_str_eq(res, "42");
    free(res);
}

Test(infin_add, carry, .init = cr_redirect_stdout)
{
    char *res = infin_add("9", "1");

    cr_assert_str_eq(res, "10");
    free(res);
}

Test(infin_add, with_zero, .init = cr_redirect_stdout)
{
    char *res = infin_add("42", "0");

    cr_assert_str_eq(res, "42");
    free(res);
}

Test(infin_add, big_carry, .init = cr_redirect_stdout)
{
    char *res = infin_add("99", "1");

    cr_assert_str_eq(res, "100");
    free(res);
}

Test(infin_sub, simple, .init = cr_redirect_stdout)
{
    char *res = infin_sub("42", "10");

    cr_assert_str_eq(res, "32");
    free(res);
}

Test(infin_sub, result_zero, .init = cr_redirect_stdout)
{
    char *res = infin_sub("5", "5");

    cr_assert_str_eq(res, "0");
    free(res);
}

Test(infin_sub, result_negative, .init = cr_redirect_stdout)
{
    char *res = infin_sub("3", "10");

    cr_assert_str_eq(res, "-7");
    free(res);
}

Test(infin_mult, simple, .init = cr_redirect_stdout)
{
    char *res = infin_mult("6", "7");

    cr_assert_str_eq(res, "42");
    free(res);
}

Test(infin_mult, by_zero, .init = cr_redirect_stdout)
{
    char *res = infin_mult("5", "0");

    cr_assert_str_eq(res, "0");
    free(res);
}

Test(infin_mult, by_one, .init = cr_redirect_stdout)
{
    char *res = infin_mult("99", "1");

    cr_assert_str_eq(res, "99");
    free(res);
}
