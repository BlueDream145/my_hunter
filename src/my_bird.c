/*
** EPITECH PROJECT, 2017
** my_bird.c
** File description:
**
*/

#include "hunter.h"

void make_bird_move(struct game *game_instance)
{
	const int bird_height = 110;
	const int screen_width = 1536;

	if (game_instance->bird->pos.x > screen_width) {
		game_instance->bird->pos.y = bird_height * rand_line_height();
		game_instance->bird->pos.x = screen_width;
		game_instance->bird->order = 1;
	}
	else if (game_instance->bird->pos.x < 0) {
		sfSprite_setScale(game_instance->bird->sprite,
		get_position(1, 1));
		game_instance->bird->pos.y = bird_height * rand_line_height();
		game_instance->bird->pos.x = 0;
		game_instance->bird->order = 0;
	}
	manage_speed(game_instance);
	sfSprite_setPosition(game_instance->bird->sprite, get_position(
		game_instance->bird->pos.x, game_instance->bird->pos.y));
	if (game_instance->bird->order == 1)
		sfSprite_setScale(game_instance->bird->sprite,
		get_position(-1, 1));
}

sfIntRect get_rect_bird_skin(struct game *game_instance)
{
	const int bird_width = 331;
	const int bird_height = 110;

	if (game_instance->bird->skin_index > 3)
		game_instance->bird->skin_index = 1;
	if (game_instance->bird->skin_index <= 1)
		return (get_rect(0, 0, bird_width / 3, bird_height));
	else if (game_instance->bird->skin_index == 2)
		return (get_rect(0, bird_width / 3, bird_width / 3,
		bird_height));
	else
		return (get_rect(0, bird_width / 3 * 2, bird_width / 3,
		bird_height));
}

void spawn_new_bird(struct game *game_instance)
{
	const int bird_height = 110;
	int y = game_instance->bird->pos.y;

	if (rand_line_height() % 2 == 0) {
		sfSprite_setScale(game_instance->bird->sprite,
		get_position(1, 1));
		game_instance->bird->order = 0;
		game_instance->bird->pos = get_position(0, y);
		game_instance->bird->pos.y = bird_height * rand_line_height();
	} else {
		sfSprite_setScale(game_instance->bird->sprite,
		get_position(-1, 1));
		game_instance->bird->order = 1;
		game_instance->bird->pos = get_position(1536, y);
		game_instance->bird->pos.y = bird_height * rand_line_height();
	}
	manage_score(game_instance);
}

void bird_miss(struct game *game_instance)
{
	game_instance->miss++;
	my_put_str("Too bad !\nMissed ");
	my_put_nbr(game_instance->miss);
	my_put_char('\n');
	load_game_text(game_instance);
	if (game_instance->miss == 2) {
		if (game_instance->score > game_instance->best_score) {
			game_instance->best_score = game_instance->score;
			sfText_setString(game_instance->best_score_field,
			my_itc(game_instance->best_score));
		}
		game_instance->step++;
		my_put_str("Final Score: ");
		my_put_nbr(game_instance->score);
		my_put_str("\nFinal Missed: ");
		my_put_nbr(game_instance->miss);
		my_put_char('\n');
	}
}

int rand_line_height(void)
{
	int line;
	time_t crt = time(NULL);
	char buf[3];

	strftime(buf, sizeof(buf), "%S", localtime(&crt));
	line = buf[1] - '0';
	if (line % 2 == 0 && line < 5)
		line += 3;
	else if (line == 0)
		line ++;
	if (line % 2 == 0 && line > 6)
		line -= 3;
	else if (line % 2 != 0 && line > 6)
		line -=5;
	return (line);
}