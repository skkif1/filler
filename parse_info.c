/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:27:38 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/15 13:27:39 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	read_player(char *data, t_player *player)
{
	get_next_line(0, &data);
	if (player->p == 0)
	{
		if (!ft_strncmp(data, "$$$ exec p1", 11))
		{
			player->p = 'O';
			player->oponent_p = 'X';
		}
		else
		{
			player->p = 'X';
			player->oponent_p = 'O';
		}
	}
	free(data);
}

static int	get_map(char *data, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	get_next_line(0, &data);
	player->map_h = ft_atoi(&data[8]);
	player->map_l = ft_atoi(&data[8 + num_len(player->map_h)]);
	player->map = (char**)malloc(sizeof(char*) * player->map_h);
	free(data);
	get_next_line(0, &data);
	free(data);
	while (data[j] == ' ')
		j++;
	while (i < player->map_h)
	{
		get_next_line(0, &data);
		player->map[i] = ft_strsub(data, j, player->map_l);
		free(data);
		i++;
	}
	return (1);
}

static void	get_figure(t_player *player, char *data)
{
	int i;

	i = 0;
	get_next_line(0, &data);
	player->figure_h = ft_atoi(&data[6]);
	player->figure_l = ft_atoi(&data[6 + num_len(player->figure_h)]);
	player->figure = (char**)malloc(sizeof(char*) * player->figure_h);
	free(data);
	while (i < player->figure_h)
	{
		get_next_line(0, &data);
		player->figure[i++] = data;
	}
}

int			main(void)
{
	char		*data;
	t_player	*player;

	data = 0;
	player = malloc(sizeof(t_player));
	player->p = 0;
	while (1)
	{
		if (player->p == 0)
			read_player(data, player);
		get_map(data, player);
		get_figure(player, data);
		find_start_point(player);
		find_place(player);
		clear_struct(player);
	}
}
