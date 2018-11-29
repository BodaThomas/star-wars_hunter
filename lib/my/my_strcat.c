/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** The task02 of the CPool Day07
*/

#include "lib.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_length + i] = src[i];
        i++;
    }
    dest[dest_length + i] = '\0';
    return (dest);
}
