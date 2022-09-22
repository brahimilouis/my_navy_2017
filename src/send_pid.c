/*
** EPITECH PROJECT, 2018
** send_pid
** File description:
** pid
*/

#include "my.h"

void send_pid(navy *st, int pid)
{
	char *nb = malloc(sizeof(char) * (8));

	nb = convert_int_str(pid, nb);
	usleep(500);
	for (int i = my_strlen(nb) - 1; i > -1; i--) {
		for (int j = 0; j < nb[i] - 48; j++) {
			kill(st->pid, SIGUSR1);
			usleep(500);
		}
		kill(st->pid, SIGUSR2);
		usleep(500);
	}
	kill(st->pid, SIGUSR2);
}
