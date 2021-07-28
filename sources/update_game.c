/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** update_game.c
*/

#include "my.h"

void terminal_is_small(char const *buffer)
{
    char const *message = "Please enlarge the terminal";

    getmaxyx(stdscr, LINES, COLS);
    while (LINES <= count_lines(buffer) || COLS <= count_cols(buffer)) {
        clear();
        mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(message)  / 2, message);
        refresh();
    }
}

cursorpos_t find_player(char **map, int rows, int cols)
{
    cursorpos_t cursor;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'P') {
                cursor.x = i;
                cursor.y = j;
            }
        }
    }
    return (cursor);
}

char **display_obstacle(char **map, obstacle_t **obstacle, int size)
{
    int i = 0;

    while (i < size) {
        if (map[obstacle[i]->x][obstacle[i]->y] == ' ') {
            map[obstacle[i]->x][obstacle[i]->y] = 'O';
        }
        i++;
    }
    return (map);
}

int check_pos(char **map, box_t **box, int i, int score)
{
    int check = score + 1;

    score = check_side_limit(map, box, i, score);
    if (score == check)
        return (score);
    score = check_side_box(map, box, i, score);
    if (score == check)
        return (score);
    score = check_xtag(map, box, i, score);
    if (score == check)
        return (score);
    score = check_tagx(map, box, i, score);
    if (score == check)
        return (score);
    return (score);
}

int update_game(char **map, box_t **box, obstacle_t **obstacle, char *buffer)
{
    int rows = count_lines(buffer);
    int cols = count_cols(buffer);
    int count_o = count_obstacle(buffer);

    if (check_win(map, obstacle, count_o) == 1)
        return (0);
    if (check_lose(map, box, rows, cols) == 1)
        return (1);
    return (2);
}