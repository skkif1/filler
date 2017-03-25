/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:05:45 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/13 17:05:46 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	calc_distance_right(t_player *player, int i, int j)
{
	int y;

	y = 0;
	while (j < player->map_l - 1)
	{
		j++;
		if (player->map[i][j] == '.')
		{
			if (y > 9)
				break ;
			player->map[i][j] = y++ + '0';
		}
		else
			break ;
	}
}

static void	calc_distance_left(t_player *player, int i, int j)
{
	int y;

	y = 0;
	while (j > 0)
	{
		j--;
		if (player->map[i][j] == '.')
		{
			if (y > 9)
				break ;
			player->map[i][j] = y++ + '0';
		}
		else
			break ;
	}
}

static void	calc_distance_top(t_player *player, int i, int j)
{
	int y;

	y = 0;
	while (i < player->map_h - 1)
	{
		i++;
		if (player->map[i][j] == '.')
		{
			if (y > 9)
				break ;
			player->map[i][j] = y++ + '0';
		}
		else
			break ;
	}
}

static void	calc_distance_bottom(t_player *player, int i, int j)
{
	int y;

	y = 0;
	while (i > 0)
	{
		i--;
		if (player->map[i][j] == '.')
		{
			if (y > 9)
				break ;
			player->map[i][j] = y++ + '0';
		}
		else
			break ;
	}
}

void		draw_distance(t_player *player)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < player->map_h)
	{
		while (j < player->map_l)
		{
			if (player->map[i][j] == player->oponent_p || player->map[i][j]
				== player->oponent_p + 32)
			{
				calc_distance_bottom(player, i, j);
				calc_distance_left(player, i, j);
				calc_distance_right(player, i, j);
				calc_distance_top(player, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
