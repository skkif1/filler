/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:58:11 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/10 16:58:12 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		find_start_point(t_player *player)
{
	int			i;
	int			j;
	static int	status;

	i = 0;
	j = 0;
	if (status == 1)
		return ;
	while (i < player->map_h)
	{
		while (j < player->map_l)
		{
			if (player->map[i][j] == player->p)
			{
				player->star_to =
				(player->map_l - j > player->map_l / 2) ? 1 : -1;
				status = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static int	if_fit(t_player *player, int h, int l)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = 0;
	j = 0;
	while (i < player->figure_h)
	{
		while (j < player->figure_l)
		{
			if (player->figure[i][j] == '*'
				&& player->map[i + h][j + l] == player->p)
				flag++;
			if (player->figure[i][j] == '*'
				&& player->map[i + h][j + l] == player->oponent_p)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void		find_place(t_player *player)
{
	int		i;
	int		j;
	t_list	*variants;

	variants = NULL;
	i = 0;
	j = 0;
	while (i < player->map_h - player->figure_h + 1)
	{
		while (j < player->map_l - player->figure_l + 1)
		{
			if (if_fit(player, i, j))
			{
				player->turn_res[0] = i;
				player->turn_res[1] = j;
				ft_lstadd_end(&variants, ft_lstnew(player->turn_res,
					sizeof(player->turn_res)));
			}
			j++;
		}
		j = 0;
		i++;
	}
	calculate(player, variants);
}
