/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** The main file of the my_hunter project
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int main(int argc, char const *argv[])
{
    sfVideoMode mode = {800, 495, 32};
    sfRenderWindow* window;
    sfTexture* background;
    sfTexture* tie;
    sfSprite* tie_sprite;
    sfSprite* background_sprite;
    sfFont* font;
    sfText* text;
    sfMusic* music;
    sfEvent event;
    int score = 0;
    float posX = 0;
    float posY = 0;
    sfVector2f tie_pos = {posX, posY};

    window = sfRenderWindow_create(mode, "Star Hunter", sfResize | sfClose, NULL);
    if (!window)
        return (84);
    background = sfTexture_createFromFile("textures/background.png", NULL);
    tie = sfTexture_createFromFile("textures/tie.png", NULL);
    if (!tie || !background)
        return (84);
    tie_sprite = sfSprite_create();
    background_sprite = sfSprite_create();
    sfSprite_setTexture(tie_sprite, tie, sfTrue);
    sfSprite_setTexture(background_sprite, background, sfTrue);
    font = sfFont_createFromFile("font/starjedi.ttf");
    if (!font)
        return (84);
    text = sfText_create();
    sfText_setString(text, "Score : ");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 15);
    music = sfMusic_createFromFile("sounds/cantina.ogg");
    if (!music)
        return (84);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        posX = posX + 0.1;
        if (posX > 800 - 127)
            posX = posX + 0.1;
        tie_pos.x = posX;
        sfSprite_setPosition(tie_sprite, tie_pos);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        sfRenderWindow_drawSprite(window, tie_sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfSprite_destroy(tie_sprite);
    sfSprite_destroy(background_sprite);
    sfTexture_destroy(tie);
    sfTexture_destroy(background);
    sfRenderWindow_destroy(window);
    return (0);
}
