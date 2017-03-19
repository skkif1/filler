/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:58:36 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/01 18:58:38 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_result;

char	*to_char(wchar_t *str)
{
	char	temp;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	res = (char*)malloc(sizeof(char) * i);
	while (j < i)
	{
		temp = (char)str[j];
		res[j] = temp;
		j++;
	}
	free(res);
	return (res);
}
