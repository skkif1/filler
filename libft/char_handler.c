/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:18:10 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/01 18:25:35 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

static	void	print_char(char *str, t_type *cons)
{
	int i;

	i = 0;
	if (cons->width == 0)
	{
		ft_putchar(str[i]);
		g_result++;
	}
	else
		while (i < cons->width)
		{
			ft_putchar(str[i]);
			g_result++;
			i++;
		}
}

void			build_arg_char(t_type *cons)
{
	char	*width;
	size_t	end;
	size_t	i;

	width = ft_strnew((size_t)cons->width);
	i = 0;
	end = (size_t)cons->width;
	if (end)
	{
		if (ft_strchr(cons->flags, '0') && !ft_strchr(cons->flags, '-'))
			while (i < end)
				width[i++] = '0';
		else
			while (i < end)
				width[i++] = ' ';
		i = (ft_strchr(cons->flags, '-')) ? 0 : end - 1;
		width[i] = cons->arg[0];
	}
	else
		width[0] = cons->arg[0];
	print_char(width, cons);
	free(width);
	free(cons->arg);
	free(cons->size);
	free(cons->flags);
}
