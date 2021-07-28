/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;
    int j = my_strlen(str1);

    while (str1[i] == str2[i] && str1[i] != '\0') {
        i++;
    }
    if (i == j)
        return (0);
    else
        return (84);
}
