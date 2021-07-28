/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** box.c
*/

#include "my.h"

int count_box(char **map, int rows, int cols)
{
    int nb = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'X') {
                nb++;
            }
        }
    }
    return (nb);
}

box_t *find_box(char **map, int rows, int cols , int nb)
{
    box_t *box = malloc(sizeof(box_t) * 1);
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'X' && index < nb) {
                index++;
                box->x = i;
                box->y = j;
            }
        }
    }
    return (box);
}

box_t **update_box(char **map, box_t **pos, int rows, int cols)
{
    int len = count_box(map, rows, cols);
    box_t **box = get_box(map, rows, cols);

    return (box);
}

box_t **get_box(char **map, int rows, int cols)
{
    int nb_box = count_box(map, rows, cols);
    box_t **box = malloc(sizeof(box_t *) * nb_box);
    int i = 0;

    while (i < nb_box) {
        box[i] = find_box(map, rows, cols, i + 1);
        i++;
    }
    return (box);
}