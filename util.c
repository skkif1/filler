/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:01:55 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/10 19:01:57 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		num_len(int num)
{
	int res;

	res = 0;
	while (num)
	{
		num = num / 10;
		res++;
	}
	return (res);
}

void	clear_struct(t_player *player)
{
	int	i;

	i = 0;
	while (i < player->map_h)
		free(player->map[i++]);
	i = 0;
	while (i < player->figure_h)
		free(player->figure[i++]);
	free(player->map);
	free(player->figure);
}

void	clear_list(t_list *list)
{
	t_list *temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->content);
		free(temp);
	}
}
