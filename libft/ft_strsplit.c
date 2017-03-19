/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:57:15 by omotyliu          #+#    #+#             */
/*   Updated: 2016/11/30 17:57:16 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*copy_word(const char *s, size_t start, char c)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = start;
	while (s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char *) * i + 1);
	while (start < i)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

static size_t		count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	num_words;
	size_t	i;
	size_t	j;
	char	**mass;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	num_words = count(s, c);
	if ((mass = (char **)malloc(sizeof(char **) * num_words + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		mass[j++] = (char *)copy_word(s, i, c);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	mass[j] = NULL;
	return (mass);
}
