/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** ...
*/

#include "my.h"

char *change_zero_str(char *str)
{
	str[0] = '0';
	return (str);
}

char *convert_int_str(int nb, char *str)
{
	int diviseur = 1;
	int division = 1;
	int i = 0;
	int k = 0;

	if (nb == 0)
		return (change_zero_str(str));
	for (;division != 0; i++) {
		division = nb / diviseur;
		diviseur = diviseur * 10;
	}
	i = i - 1;
	diviseur = diviseur / 100;
	for (; i > 0; i--) {
		str[k] = (nb / diviseur) + 48;
		nb = nb % diviseur;
		k++;
		diviseur = diviseur / 10;
	}
	str[k] = '\0';
	return (str);
}
