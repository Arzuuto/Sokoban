/*
** EPITECH PROJECT, 2020
** my_strcmp_filter
** File description:
** my_strcmp_filter.c
*/

#include "my.h"

int my_strcmp_filter(char const *str1, char const *str2, char const filter)
{
    int i = 0;
    int j = my_strlen(str1);

    while (str1[i] == str2[i] && str1[i] != '\0' && str1[i] != filter) {
        i++;
    }
    if (i == j)
        return (0);
    else
        return (84);
}
