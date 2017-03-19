/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:32:58 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/16 18:33:00 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_redup(char *src, char *str)
{
	char *str_copy;

	str_copy = (char *)malloc(sizeof(*str_copy) * (ft_strlen(str) + 1));
	if (str_copy == NULL)
		return (NULL);
	str_copy = ft_strcpy(str_copy, str);
	free(src);
	return (str_copy);
}
