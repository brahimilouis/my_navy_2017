/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** display_map_game
*/

#include "my.h"

void display_map(char **map)
{
	int i = 0;
	int j = 0;

	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	my_putstr("1|");
	while (j < 8) {
		my_putchar(map[j][i]);
		if (i != 7)
			my_putchar(' ');
		i++;
		if (i == 8) {
			my_putchar('\n');
			i = 0;
			j++;
		}
		if (i == 0 && j < 8) {
			my_putchar(j + 49);
			my_putchar('|');
		}
	}
}
