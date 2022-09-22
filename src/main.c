/*
** EPITECH PROJECT, 2018
** main
** File description:
** start game
*/

#include "my.h"

void usage(void)
{
	my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.");
	my_putstr(" pid of the first player.\n\tnavy_positions: file repre");
	my_putstr("senting the positions of the ships.\n");
}

int main(int ac, char **av)
{
	navy st;

    if (ac < 2 || ac > 3)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		usage();
		return (0);
	}
	if (ac == 2)
		connect_player(&st, av);
	if (ac == 3)
		connect_game(&st, av);
	if (st.err == 84)
		return (84);
	if (st.player == 3) {
		my_putstr("\nEnemy won\n");
		return (1);
	} else {
		my_putstr("\nI won\n");
		return (0);
	}
}
