/*
** EPITECH PROJECT, 2017
** my_utils.c
** File description:
**
*/

#include "hunter.h"

void report_error(char *str)
{
	int len = 0;

	for (len = 0; str[len]; len++);
	write(2, str, len);
	exit(84);
}

void manage_score(struct game *game_instance)
{
	game_instance->score++;
	game_instance->bird->speed -= 7;
	sfSprite_setPosition(game_instance->bird->sprite,
	game_instance->bird->pos);
	my_put_str("Score ");
	my_put_nbr(game_instance->score);
	my_put_char('\n');
	load_game_text(game_instance);
}

void manage_speed(struct game *game_instance)
{
	if ((game_instance->bird->speed < -200 &&
	game_instance->bird->move_length < 5) ||
	(game_instance->bird->speed < -100 &&
	game_instance->bird->move_length < 4) ||
	(game_instance->bird->speed < -30 &&
	game_instance->bird->move_length < 3))
		game_instance->bird->move_length++;
	if (game_instance->bird->order == 0)
		game_instance->bird->pos.x += game_instance->bird->move_length;
	else
		game_instance->bird->pos.x -= game_instance->bird->move_length;
}

char *my_itc(int nbr)
{
	int len = number_digits(nbr);
	char *result;

	result = malloc(sizeof(char) * len);
	if (result == NULL)
		report_error("Fatal error: malloc failed.");
	result[len] = '\0';
	while (len--) {
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int number_digits(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}