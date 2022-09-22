/*
** EPITECH PROJECT, 2018
** play
** File description:
** game
*/

#include "my.h"

void sig_handle(int signo)
{
	if (signo == SIGUSR1 && struc.checkss == 0) {
		my_putstr("hit\n");
		struc.checkss = 1;
	}
	if (signo == SIGUSR2 && struc.checkss == 0) {
		my_putstr("missed\n");
		struc.checkss = 2;
	}
}

void sig_win(int signo)
{
	if (signo == SIGUSR1 && struc.checkss == 0)
		struc.checkss = 1;
	if (signo == SIGUSR2 && struc.checkss == 0)
		struc.checkss = 2;
}

void take_signal_for_verif(navy *st, char *str)
{
	int i = str[0] - 'A';
	int j = str[1] - '0' - 1;

	my_putstr(str);
	my_putstr(": ");
	while (struc.checkss == 0) {
		signal(SIGUSR1, sig_handle);
		signal(SIGUSR2, sig_handle);
	}
	if (struc.checkss == 1)
		st->map_other[j][i] = 'x';
	else
		st->map_other[j][i] = 'o';
}

void verif_position(navy *st)
{
	st->game = 1;
	struc.checkss = 0;
	while (struc.checkss == 0) {
		signal(SIGUSR1, sig_win);
		signal(SIGUSR2, sig_win);
	}
	st->win = struc.checkss - 1;
	my_putchar('\n');
}

void play(navy *st)
{
	char *attack;
	int error = 0;

	struc.checkss = 0;
	if (st->player == 1)
		display_game(st);
	while (error == 0) {
		my_putstr("attack:\t");
		attack = get_next_line(0);
		if (attack == NULL) {
			st->err = 84;
			return;
		}
		if ((error = check_attack(attack)) == 0)
			my_putstr("wrong position\n");
	}
	send_signal(attack, st);
	take_signal_for_verif(st, attack);
	free(attack);
	verif_position(st);
}
