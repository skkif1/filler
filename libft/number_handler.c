/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:29:11 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/04 19:29:12 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

static	char	*add_flags_num(char *w, t_type *cons)
{
	char *f;

	f = cons->flags;
	if (w == 0)
		w = ft_strnew(2);
	w[0] = (char)((ft_strchr(f, ' ') && (!is_unsigned(cons))) ? ' ' : w[0]);
	w[0] = (char)((ft_strchr(f, '+') && (!is_unsigned(cons))) ? '+' : w[0]);
	w[0] = (char)((cons->minus) ? '-' : w[0]);
	w[0] = (char)((ft_strchr(f, '#') && (cons->type == 'o' ||
	cons->type == 'O') && cons->prec == 0 && cons->arg[ft_strlen(cons->arg) - 1]
	!= '0') ? '0' : w[0]);
	w[1] = (char)((ft_strchr(f, '#') && (cons->type == 'x')
		&& cons->arg[ft_strlen(cons->arg) - 1] != '0') ? 'x' : w[1]);
	w[1] = (char)((ft_strchr(f, '#') && (cons->type == 'X')
		&& cons->arg[ft_strlen(cons->arg) - 1] != '0') ? 'X' : w[1]);
	w[0] = (char)((ft_strchr(f, '#') && (cons->type == 'X' || cons->type == 'x')
		&& cons->num != 0) ? '0' : w[0]);
	w[1] = (char)((ft_strchr(f, '#') && ft_strchr(cons->flags, 'p')) ? 'x' :
		w[1]);
	w[0] = (char)((ft_strchr(f, '#') && ft_strchr(cons->flags, 'p')) ? '0' :
		w[0]);
	w = to_bighex(w, cons);
	return (w);
}

static	void	print_str_num(char *width, t_type *cons)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	str_size;

	i = 0;
	width = ft_append(width, cons->arg, ft_strlen(width),
		ft_strlen(cons->arg));
	if (cons->width <= (int)ft_strlen(cons->arg))
		str_size = ft_strlen(width);
	else
		str_size = cons->width;
	temp = ft_strnew(str_size);
	ft_memset(temp, ' ', cons->width);
	if (ft_strchr(cons->flags, '-'))
		j = 0;
	else
		j = str_size - ft_strlen(width);
	while (width[i] != '\0')
		temp[j++] = width[i++];
	ft_putstr(temp);
	g_result += (int)ft_strlen(temp);
	free(temp);
	free(width);
}

static	char	*add_width_num(t_type *cons)
{
	char	*width;
	size_t	arg_len;
	int		i;
	char	ch;

	i = 0;
	arg_len = ft_strlen(cons->arg);
	if (cons->width <= (int)arg_len)
		return (0);
	ch = (ft_strchr(cons->flags, '0') && cons->prec == 0 &&
	!ft_strchr(cons->flags, '-') && !ft_strchr(cons->flags, '.'))
	? '0' : ' ';
	if (ch == '0')
	{
		width = ft_strnew(cons->width - arg_len);
		while (i < (int)(cons->width - arg_len))
			width[i++] = ch;
	}
	else
		return (0);
	return (width);
}

void			build_arg_num(t_type *cons)
{
	char	*width;
	char	*prec;
	size_t	len;
	char	*str;

	str = cons->arg;
	if (cons->prec != 0)
	{
		if (cons->prec > (int)(len = ft_strlen(cons->arg)))
		{
			prec = ft_strnew(1);
			while ((int)len++ < cons->prec)
				prec = ft_append(prec, "0", ft_strlen(prec), 1);
			cons->arg = ft_append(prec, str, ft_strlen(prec), ft_strlen(str));
			free(str);
		}
	}
	width = add_width_num(cons);
	width = add_flags_num(width, cons);
	print_str_num(width, cons);
	free(cons->flags);
	free(cons->size);
	free(cons->arg);
}
