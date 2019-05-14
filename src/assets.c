/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2018
** File description:
** The assets file management of the game
*/

#include "hunter.h"

int set_assets(assets_t *assets)
{
    assets->background = sfTexture_createFromFile(BACKGROUND_PATH, NULL);
    assets->tie = sfTexture_createFromFile(TIE_PATH, NULL);
    if (!assets->tie || !assets->background)
        return (84);
    assets->tie_sprite = sfSprite_create();
    assets->background_sprite = sfSprite_create();
    sfSprite_setTexture(assets->tie_sprite, assets->tie, sfTrue);
    sfSprite_setTexture(assets->background_sprite, assets->background, sfTrue);
    assets->font = sfFont_createFromFile(FONT_PATH);
    if (!assets->font)
        return (84);
    return (0);
}
