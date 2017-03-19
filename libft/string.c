/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:16:41 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/26 14:16:42 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

int	if_string(t_type *cons, va_list list)
{
	if ((cons->type == 's' && (ft_strcmp("l", cons->size) == 0))
		|| cons->type == 'S')
	{
		free(cons->arg);
		cons->arg = to_char(va_arg(list, wchar_t*));
		cons->type = 's';
		cons->size = ft_redup(cons->size, "\0");
		if (cons->arg == NULL)
			cons->arg = "(null)";
		return (1);
	}
	if (cons->type == 's')
	{
		free(cons->arg);
		cons->arg = va_arg(list, char*);
		if (cons->arg == NULL)
			cons->arg = "(null)";
		return (1);
	}
	return (0);
}

int	if_number(t_type *cons, va_list list)
{
	char ch;

	ch = cons->type;
	if (ch == 'd' || ch == 'i' || ch == 'D')
	{
		if_snumber(cons, list);
		return (1);
	}
	if (ch == 'p')
	{
		cons->type = 'x';
		cons->size = ft_redup(cons->size, "ll");
		cons->flags = ft_append(cons->flags, "#p", ft_strlen(cons->flags), 2);
		ch = 'x';
	}
	if ((ch == 'o' || ch == 'u' || ch == 'x' || ch == 'X' || ch == 'O'
		|| ch == 'U'))
	{
		if (ch == 'o' || ch == 'O' || ch == 'x' || ch == 'X')
			cons->base = (ch == 'o' || ch == 'O') ? 8 : 16;
		if_unumber(cons, list);
		return (1);
	}
	return (0);
}

int	if_char(t_type *cons, va_list list)
{
	char ch;

	ch = cons->type;
	if (ch == 'c' || ch == 'C')
	{
		ch = (char)va_arg(list, int);
		cons->arg[0] = ch;
		return (1);
	}
	return (0);
}
