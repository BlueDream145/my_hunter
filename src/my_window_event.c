/*
** EPITECH PROJECT, 2017
** my_window_event.c
** File description:
**
*/

#include "hunter.h"

void manage_window_events(sfEvent event, struct game *game_instance)
{
	if (start_event(event, game_instance) == 0)
		return;
	if (event.type == sfEvtMouseButtonPressed &&
		event.mouseButton.button == sfMouseLeft &&
		game_instance->step == 1) {
		game_event(event, game_instance);
		return;
	}
	end_event(event, game_instance);
}

int start_event(sfEvent event, struct game *game_instance)
{
	if (event.type != sfEvtMouseButtonPressed ||
		event.mouseButton.button != sfMouseLeft ||
		game_instance->step != 0)
		return (1);
	if (event.mouseButton.x >= 470 + 130 && event.mouseButton.x <= 790 +
	130 && event.mouseButton.y >= 200 + 250 &&
	event.mouseButton.y <= 388 + 250) {
		game_instance->step++;
		game_instance->score = 0;
		game_instance->bird->speed = 80;
		game_instance->miss = 0;
		return (0);
	}
	return (1);
}

void game_event(sfEvent event, struct game *game_instance)
{
	const int bird_height = 110;

	if (event.type != sfEvtMouseButtonPressed ||
		event.mouseButton.button != sfMouseLeft ||
		game_instance->step != 1)
		return;
	if (game_instance->bird->order == 0 && event.mouseButton.x <=
		game_instance->bird->pos.x + 110 && event.mouseButton.x >=
		game_instance->bird->pos.x && event.mouseButton.y <=
		game_instance->bird->pos.y + bird_height &&
		event.mouseButton.y >= game_instance->bird->pos.y)
		spawn_new_bird(game_instance);
	else if (game_instance->bird->order == 1 && event.mouseButton.x + 110
		<= game_instance->bird->pos.x + 110 && event.mouseButton.x
		+ 110 >= game_instance->bird->pos.x && event.mouseButton.y
		<= game_instance->bird->pos.y + bird_height
		&& event.mouseButton.y >= game_instance->bird->pos.y)
		spawn_new_bird(game_instance);
	else
		bird_miss(game_instance);
}

void end_event(sfEvent event, struct game *game_instance)
{
	if (event.type != sfEvtMouseButtonPressed ||
		event.mouseButton.button != sfMouseLeft ||
		game_instance->step != 2)
		return;
	if (event.mouseButton.x >= 670 && event.mouseButton.x <= 990 &&
	event.mouseButton.y >= 550 && event.mouseButton.y <= 738) {
		game_instance->score = 0;
		game_instance->miss = 0;
		game_instance->bird->speed = 80;
		game_instance->step--;
		load_game_text(game_instance);
		return;
	}
	if (event.mouseButton.x >= 0 && event.mouseButton.x <= 209 &&
	event.mouseButton.y >= 0 && event.mouseButton.y <= 445)
		exit(0);
}