/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:38:25 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/31 17:38:26 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

static	char	*add_width(t_type *cons)
{
	char	*width;
	size_t	arg_len;

	arg_len = ft_strlen(cons->arg);
	if ((size_t)cons->width <= arg_len)
		return (0);
	width = ft_strnew(cons->width);
	return (width);
}

static	char	*add_flags(char *width, t_type *cons)
{
	size_t	end;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (width == 0)
		return (0);
	if (ft_strchr(cons->flags, '0') && !ft_strchr(cons->flags, '-'))
	{
		end = cons->width - ft_strlen(cons->arg);
		while (i < end)
			width[i++] = '0';
	}
	else
	{
		end = cons->width;
		while (i < end)
			width[i++] = ' ';
	}
	i = (ft_strchr(cons->flags, '-')) ? 0 : cons->width - ft_strlen(cons->arg);
	while (cons->arg[j] != '\0')
		width[i++] = cons->arg[j++];
	return (width);
}

static	void	build_arg(t_type *cons)
{
	char *width;
	char *str;

	if (cons->type == '\0')
		str = cons->arg;
	else
		str = ft_strdup(cons->arg);
	cons->arg = str;
	if (cons->prec != 0 || (cons->prec == 0 && (ft_strchr(cons->flags, '.'))
		&& cons->type != 0))
		cons->arg[cons->prec] = '\0';
	width = add_width(cons);
	width = add_flags(width, cons);
	if (width == 0)
	{
		ft_putstr(cons->arg);
		g_result += (int)ft_strlen(cons->arg);
	}
	else
	{
		ft_putstr(width);
		g_result += (int)ft_strlen(width);
	}
	free(width);
	free(str);
}

void			print_str(t_type *cons)
{
	if (cons->type == 0)
	{
		build_arg(cons);
		free(cons->flags);
		free(cons->size);
	}
	if (cons->type == 's')
	{
		build_arg(cons);
		free(cons->flags);
		free(cons->size);
	}
	if (cons->type == 'c' || cons->type == 'C')
		build_arg_char(cons);
	else
		return ;
}
