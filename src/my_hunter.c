/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** The main file of the my_hunter project
*/

#include "hunter.h"

int game(void)
{
    assets_t *assets = malloc(sizeof(assets_t));
    sfVideoMode mode = {800, 495, 32};
    sfRenderWindow* window;
    sfText* score_text;
    sfEvent event;
    int score = 0;
    float posX = 0;
    float posY = 0;
    sfVector2f tie_pos = {posX, posY};

    window = sfRenderWindow_create(mode, "Star Wars Hunter", sfResize | sfClose, NULL);
    if (!window)
        return (84);
    if (set_assets(assets) == 84)
        return (84);
    score_text = sfText_create();
    sfText_setString(score_text, "Score : ");
    sfText_setFont(score_text, assets->font);
    sfText_setCharacterSize(score_text, 15);
    assets->bg_music = sfMusic_createFromFile(MUSIC_PATH);
    if (!assets->bg_music)
        return (84);
    sfMusic_play(assets->bg_music);
    sfMusic_setLoop(assets->bg_music, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        posX = posX + 0.1;
        if (posX > 800)
            posX = -130;
        tie_pos.x = posX;
        sfSprite_setPosition(assets->tie_sprite, tie_pos);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, assets->background_sprite, NULL);
        sfRenderWindow_drawSprite(window, assets->tie_sprite, NULL);
        sfRenderWindow_drawText(window, score_text, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(assets->bg_music);
    sfText_destroy(score_text);
    sfFont_destroy(assets->font);
    sfSprite_destroy(assets->tie_sprite);
    sfSprite_destroy(assets->background_sprite);
    sfTexture_destroy(assets->tie);
    sfTexture_destroy(assets->background);
    sfRenderWindow_destroy(window);
    return (0);
}
