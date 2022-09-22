/*
** EPITECH PROJECT, 2018
** wait
** File description:
** other
*/

#include "my.h"

void sig_handlr(int signo)
{
	if (signo == SIGUSR2)
		struc.chec++;
	if (signo == SIGUSR1 && struc.chec == 0)
		struc.x++;
	if (signo == SIGUSR1 && struc.chec == 1)
		struc.y++;
}

void change_map(navy *st)
{
	struc.x--;
	struc.y--;
	usleep(500);
	if (st->map[struc.y][struc.x] != '.' && st->map[struc.y][struc.x]\
!= 'x' && st->map[struc.y][struc.x] != 'o') {
		kill(st->pid, SIGUSR1);
		st->map[struc.y][struc.x] = 'x';
		my_putchar(65 + struc.x);
		my_put_nbr(struc.y + 1);
		my_putstr(": hit\n\n");
	} else {
		kill(st->pid, SIGUSR2);
		if (st->map[struc.y][struc.x] != 'x') {
			st->map[struc.y][struc.x] = 'o';
			my_putchar(65 + struc.x);
			my_put_nbr(struc.y + 1);
			my_putstr(":  missed\n\n");
		}
	}
}

void recup_signal(navy *st)
{
	int verif_x = 0;
	int verif_y = 0;
	int verif_check = 0;

	while (struc.chec != 2) {
		signal(SIGUSR1, sig_handlr);
		signal(SIGUSR2, sig_handlr);
		if (verif_x != struc.x) {
			usleep(200);
			verif_x = struc.x;
			kill(st->pid, SIGUSR1);
		} else if (verif_y != struc.y) {
			usleep(200);
			verif_y = struc.y;
			kill(st->pid, SIGUSR1);
		}
		if (verif_check != struc.chec) {
			verif_check = struc.chec;
			kill(st->pid, SIGUSR1);
		}
	}
}

void wait_other(navy *st)
{
	struc.x = 0;
	struc.y = 0;
	struc.chec = 0;
	if (st->player == 2)
		display_game(st);
	my_putstr("waiting for enemy's attack...\n");
	recup_signal(st);
	change_map(st);
	st->win = check_victory(st->map);
	if (st->win == 0)
		kill(st->pid, SIGUSR1);
	else {
		kill(st->pid, SIGUSR2);
		st->player = 3;
	}
	st->game = 0;
}
