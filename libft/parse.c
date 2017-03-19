/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:42:40 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/27 20:42:40 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	parse_type(const char *str, t_type *cons)
{
	size_t i;

	i = 0;
	while (!get_spec_init(str[i]) && str[i] != '\0')
		i++;
	if (get_spec_init(str[i]))
		cons->type = str[i];
	parse_base(str, cons);
}

static	void	parse_size(const char *str, t_type *cons)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
	{
		temp = ft_strnew(1);
		while (!get_size(str[i]) && str[i] != '\0')
			i++;
		if (get_size(str[i]) && str[i + 1] == str[i])
		{
			temp = ft_append(temp, &str[i], ft_strlen(temp), 2);
			i++;
		}
		else if (get_size(str[i]))
			temp = ft_append(temp, &str[i], ft_strlen(temp), 1);
		if (size_cmp(temp, cons->size))
			cons->size = (temp[0] == '\0') ? cons->size :
		ft_redup(cons->size, temp);
		i++;
		free(temp);
	}
	parse_type(str, cons);
}

static	void	parse_prec(const char *str, t_type *cons, va_list list)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
	{
		temp = ft_strnew(1);
		if (str[i] == '.')
		{
			if (parse_wildcard((char*)&str[i], cons, list))
				;
			else
				cons->flags = ft_append(cons->flags, ".",
					ft_strlen(cons->flags), 1);
			i++;
			while (ft_isdigit(str[i]) && !get_spec_init(str[i]))
			{
				temp = ft_append(temp, &str[i++], ft_strlen(temp), 1);
				cons->prec = ft_atoi(temp);
			}
		}
		free(temp);
		i++;
	}
	parse_size(str, cons);
}

static	void	parse_width(const char *str, t_type *cons, va_list list)
{
	size_t	i;
	char	*temp;

	temp = ft_strnew(1);
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == '0' && str[i - 1] == '0') || (str[i] == '0' &&
			!ft_isdigit(str[i - 1])))
			i++;
		if (str[i] == '.')
			while ((ft_isdigit(str[i]) || str[i] == '.') && str[i] != '\0')
				i++;
		while (ft_isdigit(str[i]) && !get_spec_init(str[i]) && str[i])
		{
			temp = ft_append(temp, &str[i++], ft_strlen(temp), 1);
			cons->width = ft_atoi(temp);
		}
		cons->width = (str[i] == '*' && str[i - 1] != '.') ?
		parse_wdth_s(cons, list) : cons->width;
		temp = ft_renew(temp, 1);
		i = (str[i] == '.') ? i : i + 1;
	}
	free(temp);
	parse_prec(str, cons, list);
}

void			parse_const(const char *str, t_type *cons, va_list list)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		while (is_flag(str[i]))
		{
			if (str[i] == '0')
			{
				if (str[i - 1] == '.' || (i != 0 && ft_isdigit(str[i - 1])))
				{
					i++;
					continue;
				}
			}
			if (str[i] != '.')
				cons->flags = ft_append(cons->flags, &str[i],
			ft_strlen(cons->flags), 1);
			i++;
		}
		i++;
	}
	parse_width(str, cons, list);
}
