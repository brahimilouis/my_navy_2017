/*
** EPITECH PROJECT, 2018
** check_victory
** File description:
** ...
*/

#include "my.h"

int check_victory(char **map)
{
	int x = 0;
	int y = 0;
	int verif = 0;

	while (y != 8) {
		if (map[y][x] > 47 && map[y][x] < 59)
			verif++;
		if (map[y][x] == '\0') {
			x = -1;
			y++;
		}
		x++;
	}
	if (verif != 0)
		return (0);
	else
		return (1);
}
