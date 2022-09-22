/*
** EPITECH PROJECT, 2018
** check
** File description:
** attack
*/

#include "my.h"

int check_attack(char *str)
{
	if (my_strlen(str) != 2)
		return (0);
	if (str[0] < 65 || str[0] > 72)
		return (0);
	if (str[1] < 49 || str[1] > 56)
		return (0);
	return (1);
}
