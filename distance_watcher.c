/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_watcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:48:50 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/15 13:48:51 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	calculate(t_player *player, t_list *variants)
{
	t_list *temp;

	if (variants != NULL)
	{
		temp = variants;
		variants = choose_algo(variants, player);
		ft_printf("%d ", ((int *)variants->content)[0]);
		ft_printf("%d\n", ((int *)variants->content)[1]);
		clear_list(temp);
	}
	else
	{
		ft_printf("%d ", 0);
		ft_printf("%d\n", 0);
	}
}

int		if_closer(t_player *player, int h, int l)
{
	int i;
	int j;
	int res;

	res = 0;
	i = 0;
	j = 0;
	while (i < player->figure_h)
	{
		while (j < player->figure_l)
		{
			if (player->figure[i][j] == '*'
				&& ft_isdigit(player->map[i + h][j + l]))
				res += player->map[i + h][j + l] - 48;
			else
				res += 10;
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

int		have_contact(t_player *player)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < player->map_h - 1)
	{
		while (j < player->map_l - 1)
		{
			if (player->map[i][j] == player->p)
			{
				if (ft_isdigit(player->map[i + 1][j]) ||
					ft_isdigit(player->map[i - 1][j]) ||
					ft_isdigit(player->map[i][j + 1] ||
					ft_isdigit(player->map[i][j - 1])))
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
