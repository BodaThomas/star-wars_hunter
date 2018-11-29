/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** The task02 of the CPool Day04
*/

#include "lib.h"

int my_putstr(char const *str)
{
    int rep = 0;

    while (str[rep] != '\0')
    {
        my_putchar(str[rep]);
        rep = rep + 1;
    }
}
