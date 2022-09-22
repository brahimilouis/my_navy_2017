/*
** EPITECH PROJECT, 2018
** recup
** File description:
** pid
*/

#include "my.h"

void sig_hand(int signo)
{
	if (signo == SIGUSR1) {
		struc.nb++;
		struc.checks = 0;
	}
	if (signo == SIGUSR2) {
		if (struc.checks == 2) {
			struc.end = 1;
		} else
			struc.checks = 1;
	}
}

void recup_pid(navy *st)
{
	int i = 1;

	struc.nb = 0;
	struc.end = 0;
	struc.checks = 0;
	st->pid = 0;
	while (struc.end == 0) {
		while (struc.checks != 1 && struc.end == 0) {
			signal(SIGUSR1, sig_hand);
			signal(SIGUSR2, sig_hand);
		}
		struc.checks = 2;
		st->pid = i * struc.nb + st->pid;
		struc.nb = 0;
		i = i * 10;
	}
}
