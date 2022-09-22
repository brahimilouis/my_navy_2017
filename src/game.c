/*
** EPITECH PROJECT, 2018
** game
** File description:
** game_player
*/

#include "my.h"

void game(navy *st)
{
	while (st->win == 0 && st->err != 84) {
		if (st->game == 0)
			play(st);
		else if (st->game == 1)
			wait_other(st);
		if (st->win != 0)
			display_game(st);
	}
}
