/*
** EPITECH PROJECT, 2018
** send_signal
** File description:
** signal
*/

#include "my.h"

void sig_verif_pid(int signo)
{
	if (signo == SIGUSR1)
		struc.check = 1;
}

void verif_kill(void)
{
	struc.check = 0;
	while (struc.check == 0)
		signal(SIGUSR1, sig_verif_pid);
}

void send_signal(char *attack, navy *st)
{
	int nb = attack[0] - 'A' + 1;

	usleep(500);
	while (nb > 0) {
		kill(st->pid, SIGUSR1);
		verif_kill();
		nb--;
	}
	kill(st->pid, SIGUSR2);
	verif_kill();
	nb = attack[1] - '0';
	while (nb > 0) {
		kill(st->pid, SIGUSR1);
		verif_kill();
		nb--;
	}
	kill(st->pid, SIGUSR2);
}
