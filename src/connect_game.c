/*
** EPITECH PROJECT, 2018
** connect_game
** File description:
** connect
*/

#include "my.h"

void connect_game(navy *st, char **av)
{
	int i = kill(my_getnbr(av[1]), SIGUSR1);
	int pid = getpid();

	st->err = 0;
	st->game = 1;
	st->player = 2;
	st->pid = my_getnbr(av[1]);
	st->win = 0;
	recup_data(st, av[2]);
	if (st->err == 84)
		return;
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	recup_data(st, av[2]);
	if (st->err == 84)
		return;
	if (i != -1) {
		my_putstr("\nsuccessfully connected\n\n");
		st->map_other = create_map(st->map_other);
		send_pid(st, pid);
		game(st);
	}
}
