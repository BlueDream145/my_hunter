/*
** EPITECH PROJECT, 2017
** my_window.c
** File description:
**
*/

#include "hunter.h"

void run_window_with_sprite(sfRenderWindow *window, sfEvent event,
sfSprite *bg)
{
	struct game *game_instance = get_game_instance();
	sfClock *move_clock = sfClock_create();
	sfClock *anim_clock = sfClock_create();

	load_gui(game_instance);
	game_instance->bg = bg;
	game_instance->best_score = 0;
	my_put_str("Well done !\n");
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event))
			run_window_mouse_event(event, game_instance);
		if (sfClock_getElapsedTime(move_clock).microseconds
			/ 100 >= game_instance->bird->speed) {
			sfClock_restart(move_clock);
			run_window_draw(window, game_instance);
		}
		if (sfClock_getElapsedTime(anim_clock).microseconds
			/ 100 > 3000)
			run_window_anim(anim_clock, game_instance);
	}
}

void run_window_mouse_event(sfEvent event, struct game *game_instance)
{
	if (event.type == sfEvtClosed)
		app_exit(game_instance);
	if (event.type == sfEvtMouseMoved)
		game_instance->mouse = get_position(event.mouseMove.x - 122,
		event.mouseMove.y - 122);
	manage_window_events(event, game_instance);
}

void run_window_draw(sfRenderWindow *window, struct game *game_instance)
{
	sfRenderWindow_clear(window, sfBlack);
	window_draw(window, game_instance);
	sfRenderWindow_display(window);
}

void run_window_anim(sfClock *anim_clock, struct game *game_instance)
{
	sfClock_restart(anim_clock);
	game_instance->bird->skin_index++;
	sfSprite_setTextureRect(game_instance->bird->sprite,
	get_rect_bird_skin(game_instance));
}