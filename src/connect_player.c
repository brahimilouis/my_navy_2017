/*
** EPITECH PROJECT, 2018
** connect_player
** File description:
** connect
*/

#include "my.h"

void sig_handler(int signo)
{
	if (signo == SIGUSR1) {
		my_putstr("\nenemy connected\n\n");
		struc.check = 5;
	}
}

void connect_player(navy *st, char **av)
{
	int pid = getpid();

    st->win = 0;
	st->err = 0;
	st->player = 1;
    st->game = 0;
	recup_data(st, av[1]);
	st->map_other = create_map(st->map_other);
	if (st->err == 84)
		return;;
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putstr("\nwaiting for enemy connection...\n");
	while (struc.check != 5)
		if (signal(SIGUSR1, sig_handler) == SIG_ERR)
			my_putstr("error");
	recup_pid(st);
	game(st);
}
