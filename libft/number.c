/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:39:33 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/03 17:39:34 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*reverse_num(char *res)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(res);
	temp = ft_strnew(len--);
	while (len >= 0)
	{
		temp[i++] = res[len];
		len--;
	}
	temp[i] = '\0';
	free(res);
	return (temp);
}

char			*itoa_base(unsigned long long int num, int base)
{
	char					*res;
	int						i;
	unsigned long long int	temp;

	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	res = ft_strnew(20);
	while (num != 0)
	{
		temp = num % base;
		res[i++] = (temp < 10) ? (char)(temp + 48) : (char)(temp - 10 + 97);
		num = num / base;
	}
	res = reverse_num(res);
	return (res);
}
