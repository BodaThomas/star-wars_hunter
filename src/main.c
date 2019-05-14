/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2018
** File description:
** The main function of the game
*/

#include "hunter.h"

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        my_putstr("StarHunter is Hunter like game.\n");
        my_putstr("To start it, just type : ./my_hunter\n");
        my_putstr("Have fun!");
    }
    game();
}
