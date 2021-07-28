/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** main.c
*/

#include "my.h"

void free_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map);
}

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

int check_choice(int i)
{
    int key = getch();

    if (key == 65)
        i = 1;
    if (key == 66)
        i = 2;
    if (key == 10)
        i = i * 11;
    return (i);
}

void display_choice(int i)
{
    if (i == 1) {
        wattron(stdscr, A_REVERSE);
        mvprintw(LINES / 2 - 1, COLS / 2 - (my_strlen("START")), "START");
        wattroff(stdscr, A_REVERSE);
        mvprintw(LINES / 2 + 1, COLS / 2 - (my_strlen("START")), "QUIT ");
        move(LINES / 2 - 1, COLS / 2);
    } else if (i == 2) {
        mvprintw(LINES / 2 - 1, COLS / 2 - (my_strlen("START")), "START");
        wattron(stdscr, A_REVERSE);
        mvprintw(LINES / 2 + 1, COLS / 2 - (my_strlen("START")), "QUIT ");
        wattroff(stdscr, A_REVERSE);
        move(LINES / 2 + 1, COLS / 2);
    }
}

int display_menu(void)
{
    int i = 1;
    int key;

    initscr();
    noecho();
    box(stdscr, 0, 0);
    while (1) {
        display_choice(i);
        i = check_choice(i);
        if (i == 11 || i == 22)
            break;
    }
    if (i == 11) {
        return (1);
    } else {
        return (0);
    }
}

int start_game(char const *filepath, int size)
{
    char **map;
    char *buffer;
    int result;

    buffer = load_file_in_mem(filepath, size);
    if (check_error(buffer) == 84)
        return (84);
    map = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    if (display_menu() == 1) {
    result = my_sokoban(map, buffer, count_lines(buffer), count_cols(buffer));
    return (result);
    } else {
        endwin();
        return (2);
    }
}

int main(int argc, char **argv)
{
    struct stat bytes;
    int result;

    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
        display_usage();
        return (0);
    }
    if (stat(argv[1], &bytes) == -1)
        return (84);
    result = start_game(argv[1], bytes.st_size);
    return (result);
}