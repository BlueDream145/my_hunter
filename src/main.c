/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "hunter.h"

int main(int ac, char **as)
{
	const int screen_width = 1536;
	const int screen_height = 865;
	const char *app_name = "My Amazing Hunter";
	const char *bg_path = "resources/forest.png";
	const char *app_help = "My_Amazing_Hunter, an epitech project, based o"
	"n a duck hunt, with custom sprites.\nUsage: ./my_hunter.\n";

	if (ac == 2 && (as[1][0] == 'h' || as[1][1] == 'h')) {
		my_put_str(app_help);
		return (0);
	}
	sfVideoMode mode = { screen_width, screen_height, 32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, app_name,
		sfTitlebar | sfClose, NULL);
	sfTexture *texture_bg = sfTexture_createFromFile(bg_path, NULL);
	sfEvent event;
	run_window_with_sprite(window, event, get_sprite(texture_bg));
	dispose(texture_bg, window);
	return (0);
}

void app_exit(struct game *game_instance)
{
	my_put_str("Final Score: ");
	my_put_nbr(game_instance->score);
	my_put_str("\nFinal Missed: ");
	my_put_nbr(game_instance->miss);
	my_put_char('\n');
	exit (0);
}

void dispose(sfTexture *texture_bg, sfRenderWindow* window)
{
	sfTexture_destroy(texture_bg);
	sfRenderWindow_destroy(window);
}
