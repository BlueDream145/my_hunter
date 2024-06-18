/*
** EPITECH PROJECT, 2017
** my_put.c
** File description:
**
*/

#include "hunter.h"

int my_put_nbr(int nb)
{
	if (nb > 9)
		my_put_nbr(nb / 10);
	else if (nb < 0) {
		nb = nb * -1;
		write(1, "-", 1);
		my_put_nbr(nb / 10);
	}
	my_put_char(nb % 10 + '0');
	return (0);
}

void my_put_str(const char *str)
{
	int i = 0;

	for (i = 0; str[i]; i++)
		my_put_char(str[i]);
}

void my_put_char(char c)
{
	write(1, &c, 1);
}