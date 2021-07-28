/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** my_sokoban.c
*/

#include "my.h"

int check_win(char **map, obstacle_t **obstacle, int size)
{
    int i = 0;
    int score = 0;

    while (i < size) {
        score = check_pos_x(map, obstacle, i, score);
        if (score >= size) {
            return (1);
        }
        i++;
    }
    return (0);
}

int check_lose(char **map, box_t **box, int rows, int cols)
{
    int size = count_box(map, rows, cols);
    int i = 0;
    int score = 0;

    box = update_box(map, box, rows, cols);
    while (i < size) {
        score = check_pos(map, box, i, score);
        if (score >= size)
            return (1);
        i++;
    }
    return (0);
}

void display_map(char **map)
{
    int i = 0;

    for (i = 0; map[i] != NULL; i++)
        mvprintw(0 + i, 0, map[i]);
}

char **display_game(char **map, char *buffer, int rows, int cols)
{
    cursorpos_t cursor = find_player(map, rows, cols);

    terminal_is_small(buffer);
    display_map(map);
    move(cursor.x, cursor.y);
    map = move_player(map, buffer, cursor);
    return (map);
}

int my_sokoban(char **map, char *buffer, int rows, int cols)
{
    obstacle_t **obstacle = get_obstacle(map, buffer, rows, cols);
    box_t **box = get_box(map, rows, cols);
    int score = 2;
    int count_o = count_obstacle(buffer);

    initscr();
    noecho();
    while (score == 2) {
        clear();
        map = display_game(map, buffer, rows, cols);
        map = display_obstacle(map, obstacle, count_o);
        score = update_game(map, box, obstacle, buffer);
        refresh();
    }
    map = display_game(map, buffer, rows, cols);
    endwin();
    free_map(map);
    free(buffer);
    return (score);
}
