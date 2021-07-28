/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Write a function that counts
*/

#include "my.h"

int my_strlen(char const *str)
{
    int t = 0;
    while (str[t] != '\0'){
        t = t + 1;
    }
    return (t);
}
