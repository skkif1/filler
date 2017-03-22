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

int num_len(int num)
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

void find_start_point(t_player *player)
{

    int i;
    int j;
    static int status;

    if (status == 1)
        return ;
    i = 0;
    j = 0;
    while(i < player->map_h)
    {
        while (j < player->map_l)
        {
            if (player->map[i][j] == player->p)
            {
                player->star_to = (player->map_l - j > player->map_l / 2) ? 1 : -1;
                status = 1;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

int if_closer(t_player *player, int h, int l)
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
            if (player->figure[i][j] == '*' && ft_isdigit(player->map[i + h][j + l]))
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

int have_contact(t_player *player)
{
    int i;
    int j;

    i = 1;
    j = 1;
    while(i < player->map_h - 1)
    {
        while (j < player->map_l - 1)
        {
            if (player->map[i][j] == player->p)
            {
                if (ft_isdigit(player->map[i + 1][j]) || ft_isdigit(player->map[i - 1][j])
                    || ft_isdigit(player->map[i][j + 1]
                                  || ft_isdigit(player->map[i][j - 1])))
                    return 1;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

