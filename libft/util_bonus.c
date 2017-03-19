/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:46:07 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/18 17:46:08 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

void			parse_base(const char *str, t_type *cons)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'b')
			cons->base = 2;
		i++;
	}
}

int				parse_arg(t_type *cons, va_list list, char *temp)
{
	if (if_number(cons, list))
	{
		build_arg_num(cons);
		free(temp);
		return (1);
	}
	if (if_string(cons, list))
	{
		print_str(cons);
		free(temp);
		return (1);
	}
	if (if_char(cons, list))
	{
		print_str(cons);
		free(temp);
		return (1);
	}
	print_str(cons);
	free(temp);
	return (0);
}

void			print_ch(char *temp, int *i)
{
	while ((temp[*i] != '\0' && temp[*i] != '%'))
	{
		ft_putchar(temp[*i]);
		g_result++;
		i++;
	}
}

int				parse_wildcard(char *str, t_type *cons, va_list list)
{
	if (str[1] == '*')
	{
		cons->prec = va_arg(list, int);
		if (cons->prec == 0)
			cons->flags = ft_append(cons->flags, ".", 1,
								ft_strlen(cons->flags));
		cons->prec = (cons->prec < 0) ? 0 : cons->prec;
		return (1);
	}
	else
		cons->prec = 0;
	return (0);
}
