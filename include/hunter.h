/*
** EPITECH PROJECT, 2017
** hunter.h
** File description:
**
*/

#ifndef hunter_
#define hunter_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct game {
	int score;
	int miss;
	int step;
	int best_score;
	struct bird *bird;
	sfVector2f mouse;
	sfSprite *play;
	sfSprite *aim;
	sfSprite *bg;
	sfSprite *dog;
	sfSprite *game_over;
	sfSprite *try_again;
	sfSprite *leave;
	sfText *best_score_text;
	sfText *best_score_field;
	sfText *score_field;
	sfText *title;
	sfText *score_text;
	sfText *miss_text;
	sfText *speed_text;
	sfFont *font_julietta;
	sfFont *font_debas;
};

struct bird {
	sfSprite *sprite;
	sfVector2f pos;
	int move_length;
	int order;
	int skin_index;
	double speed;
};

// main.c
void app_exit(struct game *game_instance);
void dispose(sfTexture *texture_bg, sfRenderWindow* window);

// get.c
sfSprite *get_sprite(sfTexture* texture);
sfIntRect get_rect(int top, int left, int width, int height);
sfVector2f get_position(int x, int y);
struct game *get_game_instance(void);
struct bird *get_bird_instance(void);

// bird.c
int rand_line_height(void);
sfIntRect get_rect_bird_skin(struct game *game_instance);
void make_bird_move(struct game *game_instance);
void spawn_new_bird(struct game *game_instance);
void bird_miss(struct game *game_instance);

// put.c
int my_put_nbr(int nb);
void my_put_str(const char *str);
void my_put_char(char c);

// utils.c
void report_error(char *str);
void manage_speed(struct game *game_instance);
void manage_score(struct game *game_instance);
char *my_itc(int nbr);
int number_digits(int nbr);

// window_draw.c
void window_draw(sfRenderWindow *window, struct game *game_instance);
void window_draw_start(sfRenderWindow *window, struct game *game_instance);
void window_draw_game(sfRenderWindow *window, struct game *game_instance);
void window_draw_end(sfRenderWindow *window, struct game *game_instance);

// window_event.c
void manage_window_events(sfEvent event, struct game *game_instance);
int start_event(sfEvent event, struct game *game_instance);
void game_event(sfEvent event, struct game *game_instance);
void end_event(sfEvent event, struct game *game_instance);

// window_gui.c
void load_gui(struct game *game_instance);
void load_main_text(struct game *game_instance);
void load_game_text(struct game *game_instance);
void load_end_text(struct game *game_instance);
void load_sprites(struct game *game_instance);

// window.c
void run_window_with_sprite(sfRenderWindow *window, sfEvent event,
	sfSprite *bg);
void run_window_mouse_event(sfEvent event, struct game *game_instance);
void run_window_anim(sfClock *anim_clock, struct game *game_instance);
void run_window_draw(sfRenderWindow *window, struct game *game_instance);

#endif /* hunter_ */