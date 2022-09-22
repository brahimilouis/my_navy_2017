/*
** EPITECH PROJECT, 2018
** recup
** File description:
** data
*/

#include "my.h"

void add_data(navy *st, int nbr, int verif)
{
	int j = st->str[3] - '0' - 1;
	int i = st->str[2] - 'A';

	while (nbr > 0) {
		if (st->map[j][i] != '.') {
			st->err = 84;
			return;
		}
		st->map[j][i] = st->str[0];
		if (verif == 2)
			j++;
		else if (verif == 1)
			i++;
		if (nbr == 1 && (st->str[5] - st->str[2]) < 0)
			j -= 2;
		else if (nbr == 2 && (st->str[6] - st->str[3]) < 0)
			i -= 2;
		nbr--;
	}
}

void verif_data(navy *st)
{
	int verif = st->str[0] - 48;
	int nb1 = 0;
	int nb2 = 0;

	if ((nb1 = st->str[5] - st->str[2]) != 0) {
		if (nb1 < 0)
			nb1 = -nb1;
		if (nb1 + 1 != verif || st->str[3] != st->str[6])
			st->err = 84;
	} else if ((nb2 = st->str[6] - st->str[3]) != 0) {
		if (nb2 < 0)
			nb2 = -nb2;
		if (nb2 + 1 != verif || st->str[2] != st->str[5])
			st->err = 84;
	}
	if (st->err != 84) {
		if (nb1 != 0)
			add_data(st, nb1 + 1, 1);
		else
			add_data(st, nb2 + 1, 2);
	}
}

char **create_map(char **map)
{
	int i = 0;
	int j = 0;

	map = malloc(sizeof(char *) * (9));
	map[0] = malloc(sizeof(char) * (9));
	while (j < 8) {
		map[j][i] = '.';
		i++;
		if (i == 8) {
			map[j][i] = '\0';
			i = 0;
			j++;
		}
		if (i == 0 && j != 8)
			map[j] = malloc(sizeof(char) * (9));
	}
	return (map);
}

int check_size(char **tab)
{
	int j = 0;
	char check = '2';
	int verif = 0;

	for (int i = 0; check < '6'; i++) {
		if (tab[j][i] == check)
			verif++;
		if (i == 7) {
			i = -1;
			j++;
		}
		if (verif != check - 48 && j == 8)
			return (84);
		if (j == 8) {
			j = 0;
			check++;
			verif = 0;
		}
	}
	return (0);
}

void recup_data(navy *st, char *str)
{
	int fd;
	int i = 0;

	st->str = malloc(sizeof(char) * (100));
	st->map = create_map(st->map);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		st->err = 84;
	while (st->err != 84 && i < 4) {
		st->str = get_next_line(fd);
		if (st->str == NULL || my_strlen(st->str) != 7) {
			st->err = 84;
			return;
		}
		verif_data(st);
		i++;
	}
	if (st->err != 84 && check_size(st->map) == 84)
		st->err = 84;
	free(st->str);
}
