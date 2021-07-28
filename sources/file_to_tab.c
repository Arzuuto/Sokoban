/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** file_to_tab.c
*/

#include "my.h"

int get_tablen(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        i++;
    }
    return (i);
}

int count_lines(char const *buffer)
{
    int i = 0;
    int nb_lines = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            nb_lines++;
        }
        i++;
    }
    return (nb_lines);
}

int count_cols(char const *buffer)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\n')
        i++;
    i++;
    while (buffer[i] != '\n') {
        i++;
        j++;
    }
    return (j);
}

char **load_tab_from_file(char *file, int lines, int cols)
{
    char **array = malloc(sizeof(char *) * (lines + 1));
    int i = 0;
    int j = 0;
    int m = 0;

    if (array == NULL)
        return (NULL);
    while (i < lines) {
        array[i] = malloc(sizeof(char) * (cols + 1));
        while (file[m] != '\n') {
            array[i][j] = file[m];
            j++;
            m++;
        }
        array[i][j] = '\n';
        i++;
        m++;
        j = 0;
    }
    array[i] = NULL;
    return (array);
}

char *load_file_in_mem(char const *filepath, int size)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    int lenght;

    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return (NULL);
    lenght = read(fd, buffer, size);
    buffer[lenght] = '\0';
    close(fd);
    return (buffer);
}