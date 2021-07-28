/*
** EPITECH PROJECT, 2020
** bistromatic.h
** File description:
** macro for bistro
*/

#ifndef my_h
#define my_h

void my_putchar(char c);

void my_putstr(char const *str);

void my_put_nbr(int nb);

void my_printf(char *str, ...);

void my_put_strocta(char *str);

void my_put_hexa(int nb);

void my_puthexa_upper(int nb);

void my_put_address(long int nb);

void my_insigned_nbr(unsigned nb);

void my_put_octa(int nb);

void my_put_binary(int nb);

int my_compute_power_it(int nb, int p);

char *my_revstr(char *str);

int my_strlen(char const *str);

int my_strcmp(char const *str1, char const *str2);

int my_strcmp_filter(char const *str1, char const *str2, char const filter);

void my_puterror(char const *str);

#endif
