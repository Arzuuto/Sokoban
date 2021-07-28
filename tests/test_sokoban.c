/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** myprintf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


void  redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(map, verify_map)
{
    char *map_test = {"############\n#          #\n#   PXO    #\n#          #\n############\n"};
    char *map_res = load_file_in_mem("tests/map_with_o", 75);

    cr_assert_str_eq(map_test, map_res);
}

Test(check_error, size)
{
    char *map_test = "###";
    int i = check_error(map_test);

    cr_assert_eq(i, 84);
}

Test(check_error, player)
{
    char *map_test = "############\n#          #\n#    XO    #\n#          #\n############\n";
    int i = check_error(map_test);

    cr_assert_eq(i, 84);
}

Test(check_error, map)
{
    char *map_test = "#########V##\n# F    U   #\n#    GH    #\n#          #\n############\n";
    int i = check_error(map_test);

    cr_assert_eq(i, 84);
}

Test(check_error, object)
{
    char *map_test = "############\n#          #\n#   PXO O  #\n#          #\n############\n";
    int i = check_error(map_test);

    cr_assert_eq(i, 84);
}

Test(count, cols)
{
    char *map = load_file_in_mem("tests/map_with_o", 75); 
    int i = count_cols(map);

    cr_assert_eq(i, 12);
}

Test(count, lines)
{
    char *map = load_file_in_mem("tests/map_with_o", 75); 
    int i = count_lines(map);


    cr_assert_eq(i, 5);
}

Test(count, obstacle)
{
    char *map = load_file_in_mem("tests/map_with_o", 75); 
    int i = count_obstacle(map);

    cr_assert_eq(i, 1);
}

Test(pos, pos_p)
{
    char *buffer = load_file_in_mem("tests/map_with_o", 75);
    char **map = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    cursorpos_t pos = find_player(map, count_lines(buffer), count_cols(buffer));

    cr_assert_eq(pos.x, 2);
    cr_assert_eq(pos.y, 4);
}
Test(map_tab, verify_map)
{
    char *buffer = load_file_in_mem("tests/map_with_o", 75);
    char *map_test[] = {"############\n", "#          #\n", "#   PXO    #\n", "#          #\n", "############\n"};
    char **map_res = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));

    for (int i = 0; i < 5; i++)
        cr_assert_str_eq(map_test[i], map_res[i]);
}

Test(obstacle, get_obstacle)
{
    char *buffer = load_file_in_mem("map/map1", 75);
    char **map = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));

    obstacle_t **obstacle = get_obstacle(map, buffer, count_lines(buffer), count_cols(buffer));
    cr_assert_eq(obstacle[0]->x, 2);
    cr_assert_eq(obstacle[0]->y, 6);
}

Test(box, get_box)
{
    char *buffer = load_file_in_mem("tests/map_with_o", 75);
    char **map = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));

    box_t **box = get_box(map, count_lines(buffer), count_cols(buffer));
    cr_assert_eq(box[0]->x, 2);
    cr_assert_eq(box[0]->y, 5);
}

Test(obstacle, display_obstacle)
{
    char *buffer = load_file_in_mem("tests/map_without_o", 75);
    char *buffer_o = load_file_in_mem("tests/map_with_o", 75);
    char **map_without_o = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_with_o = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    obstacle_t **obstacle = get_obstacle(map_with_o, buffer_o, count_lines(buffer_o), count_cols(buffer_o));

    map_without_o = display_obstacle(map_without_o, obstacle, count_obstacle(buffer_o));
    for (int i = 0; i < 5; i++)
        cr_assert_str_eq(map_with_o[i], map_without_o[i]);
}

Test(game, move_up)
{
    char *buffer = load_file_in_mem("tests/map_move_up", 75);
    char *buffer_o = load_file_in_mem("tests/map_up", 75);
    char **map_move_up = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_up = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    cursorpos_t pos = find_player(map_move_up, count_lines(buffer), count_cols(buffer));

    map_move_up = move_up(map_move_up, pos);
    for (int i = 0; i < 5; i++)
        cr_assert_str_eq(map_move_up[i], map_up[i]);
}

Test(game, move_right)
{
    char *buffer = load_file_in_mem("tests/map_move_right", 75);
    char *buffer_o = load_file_in_mem("tests/map_right", 75);
    char **map_move_right = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_right = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    cursorpos_t pos = find_player(map_move_right, count_lines(buffer), count_cols(buffer));

    map_move_right = move_right(map_move_right, pos);
    for (int i = 0; i < 5; i++)
        cr_assert_str_eq(map_move_right[i], map_right[i]);
}

Test(game, move_down)
{
    char *buffer = load_file_in_mem("tests/map_move_down", 75);
    char *buffer_o = load_file_in_mem("tests/map_down", 75);
    char **map_move_down = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_down = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    cursorpos_t pos = find_player(map_move_down, count_lines(buffer), count_cols(buffer));

    map_move_down = move_down(map_move_down, pos);
    for (int i = 0; i < 5; i++)
        cr_assert_str_eq(map_move_down[i], map_down[i]);
}

Test(game, move_left)
{
    char *buffer = load_file_in_mem("tests/map_move_left", 75);
    char *buffer_o = load_file_in_mem("tests/map_left", 75);
    char **map_move_left = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_left = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    cursorpos_t pos = find_player(map_move_left, count_lines(buffer), count_cols(buffer));

    map_move_left = move_left(map_move_left, pos);
    for (int i = 0; i < 5; i++)
        cr_assert_str_eq(map_move_left[i], map_left[i]);
}

Test(game, lose)
{
    char *buffer = load_file_in_mem("tests/map_move_left", 75);
    char *buffer_o = load_file_in_mem("tests/map_lose", 75);
    char **map_move_left = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_left = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    cursorpos_t pos = find_player(map_move_left, count_lines(buffer), count_cols(buffer));
    obstacle_t **obstacle = get_obstacle(map_move_left, buffer, count_lines(buffer), count_cols(buffer));
    box_t **box = get_box(map_move_left, count_lines(buffer), count_cols(buffer));
    int score = 0;

    map_move_left = move_left(map_move_left, pos);
    score = update_game(map_left, box, obstacle, buffer);
    cr_assert_eq(score, 1);
}

Test(game, win)
{
    char *buffer = load_file_in_mem("tests/map_move_left", 75);
    char *buffer_o = load_file_in_mem("tests/map_left", 75);
    char **map_move_left = load_tab_from_file(buffer, count_lines(buffer), count_cols(buffer));
    char **map_left = load_tab_from_file(buffer_o, count_lines(buffer_o), count_cols(buffer_o));
    cursorpos_t pos = find_player(map_move_left, count_lines(buffer), count_cols(buffer));
    obstacle_t **obstacle = get_obstacle(map_move_left, buffer, count_lines(buffer), count_cols(buffer));
    box_t **box = get_box(map_move_left, count_lines(buffer), count_cols(buffer));
    int score = 0;

    map_move_left = move_left(map_move_left, pos);
    score = update_game(map_left, box, obstacle, buffer);
    cr_assert_eq(score, 0);
}