/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:58:57 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/31 18:58:59 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_wdth_s(t_type *cons, va_list list)
{
	int temp;

	temp = va_arg(list, int);
	if (temp < 0)
	{
		cons->flags = ft_append(cons->flags, "-", ft_strlen(cons->flags), 1);
		temp = -(temp);
	}
	return (temp);
}

int		is_unsigned(t_type *cons)
{
	char ch;

	ch = cons->type;
	if (ch == 'o' || ch == 'O' || ch == 'x' || ch == 'X' || ch == 'u' ||
			ch == 'U')
		return (1);
	return (0);
}

int		is_flag(char ch)
{
	if (ch == '#' || ch == '0' || ch == '-' || ch == '+' ||
			ch == ' ' || ch == '.')
		return (1);
	return (0);
}

char	*to_bighex(char *width, t_type *cons)
{
	int i;

	i = 0;
	if (cons->type == 'X')
	{
		while (cons->arg[i] != '\0')
		{
			cons->arg[i] = (ft_isalpha(cons->arg[i])) ?
			(char)(cons->arg[i] - 32) : cons->arg[i];
			i++;
		}
	}
	return (width);
}

void	check_null(long long int temp, t_type *cons)
{
	if (temp == 0 && cons->prec == 0 && ft_strchr(cons->flags, '.'))
	{
		if (ft_strchr(cons->flags, '#') && (cons->type == 'o' ||
			cons->type == 'O'))
		{
			cons->type = '\0';
			return ;
		}
		else
			cons->arg[0] = '\0';
	}
}
