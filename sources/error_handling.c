/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** error_handling.c
*/

#include "my.h"

int check_size(char const *str)
{
    if (my_strlen(str) < 3) {
        return (84);
    }
    return (0);
}

int check_player(char const *str)
{
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'P')
            index++;
    }
    if (index != 1) {
        return (84);
    }
    return (0);
}

int check_map(char const *str)
{
    int i = 0;

    while (str[i] == '#' || str[i] == 'P' || str[i] == 'X' || str[i] == 'O' ||
           str[i] == ' ' || str[i] == '\n')
        i++;
    if (str[i] == '\0' && str[0] != '\0')
        return (0);
    return (84);
}

int check_object(char const *str)
{
    int box = 0;
    int obstacle = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'X')
            box++;
        if (str[i] == 'O')
            obstacle++;
    }
    if (box == obstacle)
        return (0);
    else
        return (84);
}

int check_error(char const *str)
{
    if (check_size(str) == 84 || check_player(str) == 84
        || check_map(str) == 84 || check_object(str)) {
        return (84);
    }
    return (0);
}
