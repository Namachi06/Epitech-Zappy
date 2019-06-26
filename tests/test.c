/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** function
*/

#include <criterion/criterion.h>

Test(misc, failing) {
    cr_assert(0, "Hello world.");
}