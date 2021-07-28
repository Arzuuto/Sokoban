/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** main.c
*/

#include "my.h"

void display_usage(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map  file representing the warehouse map,");
    my_printf(" containing '#' for walls,\n");
    my_printf("          'P' for the palyer, 'X' for boxes");
    my_printf(" and '0', for storage locations.\n");
}

int main(int argc, char **argv)
{
    struct stat bytes;
    char *buffer;
    char **map;
    int result;

    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
        display_usage();
        return (0);
    }
    if (stat(argv[1], &bytes) == -1)
        return (84);
    buffer = load_file_in_mem(argv[1], bytes.st_size);
    if (check_error(buffer) == 84)
        return (84);
    map = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    result = my_sokoban(map, buffer, count_lines(buffer), count_cols(buffer));
    return (result);
}
