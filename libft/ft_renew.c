/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:38:42 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/16 18:41:14 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_renew(char *strold, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size + 1);
	if (str != NULL)
	{
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
	}
	free(strold);
	return (str);
}
