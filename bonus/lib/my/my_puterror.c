/*
** EPITECH PROJECT, 2020
** myputerror
** File description:
** write in the outpout of error
*/

#include <unistd.h>

void my_puterror(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        write(2, &str[i], 1);
        i++;
    }
    return;
}
