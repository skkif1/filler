/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:17:13 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/28 16:17:14 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_spec(char ch)
{
	if (ch == 's' || ch == 'S' || ch == 'p' || ch == 'D' || ch == 'i'
		|| ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' || ch == 'x'
		|| ch == 'X' || ch == 'c' || ch == 'C' || ch == '\0' || ch == 'd')
		return (0);
	return (1);
}

char	get_spec_init(char ch)
{
	if (ch == 's' || ch == 'S' || ch == 'p' || ch == 'D' || ch == 'i'
		|| ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' || ch == 'x'
		|| ch == 'X' || ch == 'c' || ch == 'C' || ch == 'd')
		return (ch);
	return (0);
}

int		get_flag(char ch)
{
	if (ch == '+' || ch == ' ' || ch == '-' || ch == '#' || ch == '0'
		|| ch == '.' || ft_isdigit(ch) || ch == 'h' || ch == 'l' || ch == 'j'
		|| ch == 'z' || ch == '*' || ch == 'b')
		return (1);
	return (0);
}

int		get_size(char ch)
{
	if (ch == 'h' || ch == 'l' || ch == 'j' || ch == 'z')
		return (1);
	return (0);
}

int		size_cmp(char *temp, char *cons)
{
	char	**mass;
	int		i;
	int		a;
	int		b;

	i = -1;
	a = 0;
	b = 0;
	mass = (char**)malloc(sizeof(char*) * 6);
	mass[0] = "hh\0";
	mass[1] = "h\0";
	mass[2] = "l\0";
	mass[3] = "ll\0";
	mass[4] = "j\0";
	mass[5] = "z\0";
	while (i++ < 5)
		if (!ft_strcmp(temp, mass[i]))
			a = i;
	i = -1;
	while (i++ < 5)
		if (!ft_strcmp(cons, mass[i]))
			b = i;
	free(mass);
	return (a >= b);
}
