/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int i_2 = 0;

	while (dest[i] != '\0')
		i = i + 1;
	while (src[i_2] != '\0' && nb > i_2) {
		dest[i] = src[i_2];
		i = i + 1;
		i_2 = i_2 + 1;
	}
	dest[i] = '\0';
	return (dest);
}

int verif_line_gnl(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char *get_next_line(int fd)
{
	char *str = malloc(sizeof(char) * (1 + 1));
	char *add_str = malloc(sizeof(char) * (1 + 1));
	int verif = -1;
	int i = 1;

	while (verif == -1 && i > 0) {
		i = read(fd, add_str, 1);
		if (i == 0)
			return (NULL);
		add_str[i] = '\0';
		verif = verif_line_gnl(add_str);
		if (verif == -1)
			str = my_strncat(str, add_str, 1);
		else
			str = my_strncat(str, add_str, verif);
	}
	if (i == 0)
		return (NULL);
	return (str);
}
