/*
** EPITECH PROJECT, 2020
** bistromatic.h
** File description:
** macro for bistro
*/

#ifndef my_h
#define my_h

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
typedef struct cursorpos_s {
    int x;
    int y;
    int i;
} cursorpos_t;

typedef struct obstacle_s {
    int x;
    int y;
} obstacle_t;

typedef struct box_s {
    int x;
    int y;
} box_t;

void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_printf(char *str, ...);
void my_put_strocta(char *str);
void my_put_hexa(int nb);
void my_puthexa_upper(int nb);
void my_put_address(long int nb);
void my_insigned_nbr(unsigned nb);
void my_put_octa(int nb);
void my_put_binary(int nb);
int my_compute_power_it(int nb, int p);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);

char *load_file_in_mem(char const *filepath, int size);
char **load_tab_from_file(char *file, int LINES, int cols);
int my_sokoban(char **map, char *buffer, int rows, int cols);
char **display_game(char **map, char *buffer, int rows, int cols);
int update_game(char **map, box_t **box, obstacle_t **obstacle, char *buffer);
int check_pos(char **map, box_t **box, int i, int score);
char **display_obstacle(char **map, obstacle_t **obstacle, int size);
cursorpos_t find_player(char **map, int rows, int cols);
void terminal_is_small(char const *buffer);
void display_map(char **map);
int check_lose(char **map, box_t **box, int rows, int cols);
int check_win(char **map, obstacle_t **obstacle, int size);
obstacle_t *find_obstacle(char **map, int rows, int cols , int nb);
int count_obstacle(char *buffer);
obstacle_t **get_obstacle(char **map, char *buffer, int rows, int cols);
box_t **get_box(char **map, int rows, int cols);
box_t **update_box(char **map, box_t **pos, int rows, int cols);
box_t *find_box(char **map, int rows, int cols , int nb);
int count_box(char **map, int rows, int cols);
int count_lines(char const *buffer);
int count_cols(char const *buffer);
int get_tablen(char **map);
int check_side_limit(char **map, box_t **box, int i, int score);
int check_side_box(char **map, box_t **box, int i, int score);
int check_xtag(char **map, box_t **box, int i, int score);
int check_tagx(char **map, box_t **box, int i, int score);
int check_pos_x(char **map, obstacle_t **obstacle, int i, int score);
int check_error(char const *str);
int check_object(char const *str);
int check_map(char const *str);
int check_player(char const *str);
int check_size(char const *str);
void free_map(char **map);
void display_usage(void);
char **move_up(char **map, cursorpos_t pos);
char **move_down(char **map, cursorpos_t pos);
char **move_right(char **map, cursorpos_t pos);
char **move_left(char **map, cursorpos_t pos);
char **move_player(char **map, char *str, cursorpos_t cursor);

#endif
