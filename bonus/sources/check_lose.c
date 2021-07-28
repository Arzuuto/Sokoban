/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** check_lose.c
*/

#include "my.h"

int check_side_limit(char **map, box_t **box, int i, int score)
{
    int j = 0;

    if (map[box[i]->x + 1][box[i]->y] == '#' &&
        map[box[i]->x][box[i]->y + 1] == '#')
        j++;
    if (map[box[i]->x + 1][box[i]->y] == '#' &&
        map[box[i]->x][box[i]->y - 1] == '#')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == '#' &&
        map[box[i]->x][box[i]->y + 1] == '#')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == '#' &&
        map[box[i]->x][box[i]->y - 1] == '#')
        j++;
    if (j >= 1)
        score++;
    return (score);
}

int check_side_box(char **map, box_t **box, int i, int score)
{
    int j = 0;

    if (map[box[i]->x + 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y + 1] == 'X')
        j++;
    if (map[box[i]->x + 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y - 1] == 'X')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y + 1] == 'X')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y - 1] == 'X')
        j++;
    if (j >= 1)
        score++;
    return (score);
}

int check_xtag(char **map, box_t **box, int i, int score)
{
    int j = 0;

    if (map[box[i]->x + 1][box[i]->y] == '#' &&
        map[box[i]->x][box[i]->y + 1] == 'X')
        j++;
    if (map[box[i]->x + 1][box[i]->y] == '#' &&
    map[box[i]->x][box[i]->y - 1] == 'X')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == '#' &&
        map[box[i]->x][box[i]->y + 1] == 'X')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == '#' &&
    map[box[i]->x][box[i]->y - 1] == 'X')
        j++;
    if (j >= 1)
        score++;
    return (score);
}

int check_tagx(char **map, box_t **box, int i, int score)
{
    int j = 0;

    if (map[box[i]->x + 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y + 1] == '#')
        j++;
    if (map[box[i]->x + 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y - 1] == '#')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y + 1] == '#')
        j++;
    if (map[box[i]->x - 1][box[i]->y] == 'X' &&
        map[box[i]->x][box[i]->y - 1] == '#')
        j++;
    if (j >= 1)
        score++;
    return (score);
}

int check_pos_x(char **map, obstacle_t **obstacle, int i, int score)
{
    if (map[obstacle[i]->x][obstacle[i]->y] == 'X')
        score++;
    return (score);
}
