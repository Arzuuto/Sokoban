/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** move.c
*/

#include "my.h"

char **move_up(char **map, cursorpos_t pos)
{
    if (map[pos.x - 1][pos.y] == ' ' || map[pos.x - 1][pos.y] == 'O') {
        map[pos.x - 1][pos.y] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    if (map[pos.x - 1][pos.y] == 'X' && map[pos.x - 2][pos.y] != '#'
        && map[pos.x - 1][pos.y] == 'X' && map[pos.x - 2][pos.y] != 'X') {
        map[pos.x - 2][pos.y] = 'X';
        map[pos.x - 1][pos.y] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    refresh();
    return (map);
}

char **move_down(char **map, cursorpos_t pos)
{
    if (map[pos.x + 1][pos.y] == ' ' || map[pos.x + 1][pos.y] == 'O') {
        map[pos.x + 1][pos.y] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    if (map[pos.x + 1][pos.y] == 'X' && map[pos.x + 2][pos.y] != '#'
        && map[pos.x + 1][pos.y] == 'X' && map[pos.x + 2][pos.y] != 'X') {
        map[pos.x + 2][pos.y] = 'X';
        map[pos.x + 1][pos.y] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    refresh();
    return (map);
}

char **move_right(char **map, cursorpos_t pos)
{
    if (map[pos.x][pos.y + 1] == ' ' || map[pos.x][pos.y + 1] == 'O') {
        map[pos.x][pos.y + 1] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    if (map[pos.x][pos.y + 1] == 'X' && map[pos.x][pos.y + 2] != '#'
        && map[pos.x][pos.y + 1] == 'X' && map[pos.x][pos.y + 2] != 'X') {
        map[pos.x][pos.y + 2] = 'X';
        map[pos.x][pos.y + 1] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    refresh();
    return (map);
}

char **move_left(char **map, cursorpos_t pos)
{
    if (map[pos.x][pos.y - 1] == ' ' || map[pos.x][pos.y - 1] == 'O') {
        map[pos.x][pos.y - 1] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    if (map[pos.x][pos.y - 1] == 'X' && map[pos.x][pos.y - 2] != '#'
        && map[pos.x][pos.y - 1] == 'X' && map[pos.x][pos.y - 2] != 'X') {
        map[pos.x][pos.y - 2] = 'X';
        map[pos.x][pos.y - 1] = 'P';
        map[pos.x][pos.y] = ' ';
    }
    refresh();
    return (map);
}

char **move_player(char **map, char *str, cursorpos_t cursor)
{
    int key;

    keypad(stdscr, TRUE);
    key = getch();
    if (key == ' ')
        map = load_tab_from_file(str, count_lines(str), count_cols(str));
    if (key == KEY_UP)
        map = move_up(map, cursor);
    if (key == KEY_DOWN)
        map = move_down(map, cursor);
    if (key == KEY_RIGHT)
        map = move_right(map, cursor);
    if (key == KEY_LEFT)
        map = move_left(map, cursor);
    return (map);
}
