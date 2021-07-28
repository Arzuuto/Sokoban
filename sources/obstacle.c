/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** obstacle.c
*/

#include "my.h"

int count_obstacle(char *buffer)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'O')
            nb++;
    }
    return (nb);
}

obstacle_t *find_obstacle(char **map, int rows, int cols , int nb)
{
    obstacle_t *obstacle = malloc(sizeof(obstacle_t) * 1);
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'O' && index < nb) {
                index++;
                obstacle->x = i;
                obstacle->y = j;
            }
        }
    }
    return (obstacle);
}

obstacle_t **get_obstacle(char **map, char *buffer, int rows, int cols)
{
    int nb_obstacle = count_obstacle(buffer);
    obstacle_t **obstacle = malloc(sizeof(obstacle_t *) * nb_obstacle);
    int i = 0;

    while (i < nb_obstacle) {
        obstacle[i] = find_obstacle(map, rows, cols, i + 1);
        i++;
    }
    return (obstacle);
}