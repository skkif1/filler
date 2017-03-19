/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:19:08 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/09 19:19:09 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_snumber(t_type *cons, va_list list)
{
	char			*type;
	long long int	temp;

	type = cons->size;
	if (!ft_strcmp(type, "hh") && cons->type != 'D' && cons->type != 'D')
		temp = (char)va_arg(list, int);
	else if (!ft_strcmp(type, "h") && cons->type != 'D' && cons->type != 'D')
		temp = (short int)va_arg(list, int);
	else if (!ft_strcmp(type, "z"))
		temp = va_arg(list, size_t);
	else if (!ft_strcmp(type, "l") || !ft_strcmp(type, "ll") ||
		!ft_strcmp(type, "j") || cons->type == 'D')
		temp = (intmax_t)va_arg(list, long long int);
	else
		temp = va_arg(list, int);
	cons->minus = (temp < 0) ? 1 : 0;
	temp = (cons->minus) ? -(temp) : temp;
	cons->num = temp;
	free(cons->arg);
	cons->arg = itoa_base((unsigned long long int)temp, cons->base);
	check_null(temp, cons);
	return (1);
}

int	if_unumber(t_type *cons, va_list list)
{
	char					*type;
	unsigned long long int	temp;

	type = cons->size;
	if (!ft_strcmp(type, "hh") && cons->type != 'O' && cons->type != 'U')
		temp = (unsigned char)va_arg(list, int);
	else if (!ft_strcmp(type, "h") && cons->type != 'U')
		temp = (unsigned short int)va_arg(list, int);
	else if (!ft_strcmp(type, "z"))
		temp = va_arg(list, unsigned long long int);
	else if (!ft_strcmp(type, "l") || !ft_strcmp(type, "ll") ||
			!ft_strcmp(type, "j") || cons->type == 'U' || cons->type == 'O')
		temp = va_arg(list, unsigned long long int);
	else
		temp = va_arg(list, unsigned int);
	cons->num = temp;
	free(cons->arg);
	cons->arg = itoa_base(temp, cons->base);
	check_null(temp, cons);
	return (1);
}
