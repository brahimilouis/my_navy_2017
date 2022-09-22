/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** oui
*/

#include "my.h"

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}
