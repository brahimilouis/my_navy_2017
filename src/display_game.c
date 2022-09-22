/*
** EPITECH PROJECT, 2018
** display_game
** File description:
** display
*/

#include "my.h"

void display_game(navy *st)
{
	my_putstr("my positions:\n");
	display_map(st->map);
	my_putstr("\nenemy's positions:\n");
	display_map(st->map_other);
	my_putchar('\n');
}
