/*
** EPITECH PROJECT, 2017
** my_window_draw.c
** File description:
**
*/

#include "hunter.h"

void window_draw(sfRenderWindow *window, struct game *game_instance)
{
	if (game_instance->step == 0)
		window_draw_start(window, game_instance);
	if (game_instance->step == 1)
		window_draw_game(window, game_instance);
	if (game_instance->step == 2)
		window_draw_end(window, game_instance);
}

void window_draw_start(sfRenderWindow *window, struct game *game_instance)
{
	if (game_instance->step != 0)
		return;
	sfRenderWindow_setMouseCursorVisible(window, sfTrue);
	sfText_setPosition(game_instance->title, get_position(410, 200));
	sfRenderWindow_drawSprite(window, game_instance->bg, NULL);
	sfRenderWindow_drawSprite(window, game_instance->play, NULL);
	sfRenderWindow_drawText(window, game_instance->title, NULL);
}

void window_draw_game(sfRenderWindow *window, struct game *game_instance)
{
	if (game_instance->step != 1)
		return;
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	sfSprite_setPosition(game_instance->aim, game_instance->mouse);
	make_bird_move(game_instance);
	sfRenderWindow_drawSprite(window, game_instance->bg, NULL);
	sfRenderWindow_drawSprite(window, game_instance->bird->sprite, NULL);
	sfRenderWindow_drawSprite(window, game_instance->aim, NULL);
	sfRenderWindow_drawText(window, game_instance->score_field, NULL);
	sfRenderWindow_drawText(window, game_instance->score_text, NULL);
	sfRenderWindow_drawText(window, game_instance->miss_text, NULL);
	sfRenderWindow_drawText(window, game_instance->speed_text, NULL);
}

void window_draw_end(sfRenderWindow *window, struct game *game_instance)
{
	if (game_instance->step != 2)
		return;
	sfRenderWindow_setMouseCursorVisible(window, sfTrue);
	sfRenderWindow_drawSprite(window, game_instance->bg, NULL);
	sfText_setPosition(game_instance->title, get_position(410, 20));
	sfSprite_setPosition(game_instance->dog, get_position(150, 450));
	sfSprite_setPosition(game_instance->try_again, get_position(670, 550));
	sfSprite_setPosition(game_instance->game_over, get_position(620, 265));
	sfRenderWindow_drawSprite(window, game_instance->dog, NULL);
	sfRenderWindow_drawText(window, game_instance->title, NULL);
	sfRenderWindow_drawSprite(window, game_instance->game_over, NULL);
	sfRenderWindow_drawSprite(window, game_instance->leave, NULL);
	sfRenderWindow_drawSprite(window, game_instance->try_again, NULL);
	sfRenderWindow_drawText(window, game_instance->score_field, NULL);
	sfRenderWindow_drawText(window, game_instance->score_text, NULL);
	sfRenderWindow_drawText(window, game_instance->miss_text, NULL);
	sfRenderWindow_drawText(window, game_instance->speed_text, NULL);
	sfRenderWindow_drawText(window, game_instance->best_score_field, NULL);
	sfRenderWindow_drawText(window, game_instance->best_score_text, NULL);
}