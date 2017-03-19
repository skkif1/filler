/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:26:08 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/28 17:26:14 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

static	t_type	*init_type(t_type *cons)
{
	cons->flags = ft_strnew(1);
	cons->width = 0;
	cons->prec = 0;
	cons->size = ft_strnew(1);
	cons->arg = ft_strnew(1);
	cons->type = 0;
	cons->num = 0;
	cons->base = 10;
	cons->minus = 0;
	return (cons);
}

static	t_type	*init_arg(char *format, va_list list, t_type *cons)
{
	cons = init_type(cons);
	parse_const(format, cons, list);
	return (cons);
}

static	char	*parse_sub_str(char *str, t_type *cons, va_list list)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		while (get_flag(str[i]) && str[i] != '\0')
			i++;
		if (!get_spec_init(str[i]))
		{
			temp = ft_strsub(str, 0, i + 1);
			cons = init_arg(temp, list, cons);
			cons->arg[0] = str[i];
			parse_arg(cons, list, temp);
			return (&str[i + 1]);
		}
		if (get_spec_init(str[i]))
		{
			temp = ft_strsub(str, 0, i + 1);
			cons = init_arg(temp, list, cons);
			parse_arg(cons, list, temp);
			return (&str[i + 1]);
		}
	}
	return (&str[i]);
}

static	void	init_arg_wraper(char *temp, va_list list, t_type *cons)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		while ((temp[i] != '\0' && temp[i] != '%'))
		{
			ft_putchar(temp[i++]);
			g_result++;
		}
		if (temp[i] == '\0')
			break ;
		if (temp[i + 1] == '%')
		{
			ft_putchar(temp[i]);
			g_result++;
			i += 2;
			continue ;
		}
		else
			temp = parse_sub_str(&temp[i + 1], cons, list);
		i = 0;
	}
}

int				ft_printf(const char *restrict format, ...)
{
	char	*tempformat;
	t_type	*cons;
	va_list argptr;
	int		temp;

	cons = (t_type*)malloc(sizeof(t_type));
	va_start(argptr, format);
	tempformat = (char *)format;
	init_arg_wraper(tempformat, argptr, cons);
	temp = g_result;
	g_result = 0;
	va_end(argptr);
	free(cons);
	return (temp);
}
