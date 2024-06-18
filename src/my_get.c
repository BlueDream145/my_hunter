/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include "hunter.h"

sfSprite *get_sprite(sfTexture* texture)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, texture, sfTrue);
	return (sprite);
}

sfVector2f get_position(int x, int y)
{
	sfVector2f vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfIntRect get_rect(int top, int left, int width, int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

struct game *get_game_instance(void)
{
	struct game *game_instance = malloc(sizeof(struct game));

	if (game_instance == NULL)
		report_error("Fatal error: malloc failed.");
	game_instance->score = 0;
	game_instance->miss = 0;
	game_instance->step = 0;
	return (game_instance);
}

struct bird *get_bird_instance(void)
{
	struct bird *bird_instance = malloc(sizeof(struct bird));

	if (bird_instance == NULL)
		report_error("Fatal error: malloc failed.");
	bird_instance->move_length = 2;
	bird_instance->speed = 80;
	bird_instance->skin_index = 1;
	bird_instance->order = 0;
	bird_instance->pos = get_position(0, 0);
	return (bird_instance);
}