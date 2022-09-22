/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** ...
*/

#include "my.h"

int my_put_nbr(int nb)
{
	int reste;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb > 9) {
			reste = nb % 10;
			nb = (nb - reste) / 10;
			my_put_nbr(nb);
			my_putchar(48 + reste);
		} else
			my_putchar(48 + nb);
	}
	return (0);
}
