/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:36:06 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/12 19:36:07 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


static t_list *choose_better(t_list *list, int(*cmp)(t_list *list1, t_list *t_list2, t_player *player), t_player *player)
{
    t_list *temp;
    t_list *result;

    temp = list;
    result = temp;
    while (temp->next)
    {
        if (cmp(result, temp->next, player))
        {
            result = temp->next;
        }
        temp = temp->next;
    }
    return result;
}

static int go_right(t_list *list1, t_list *list2, t_player *player)
{
    int first;
    int second;

    first = ((int*)(list1->content))[1];
    second = ((int*)(list2->content))[1];

    if (player->figure_l - first > player->figure_l - second)
        return 1;
    return 0;
}

static int go_left(t_list *list1, t_list *list2, t_player *player)
{
    int first;
    int second;

    first = ((int *) (list1->content))[1];
    second = ((int *) (list2->content))[1];

    if (player->figure_l - first < player->figure_l - second)
        return 1;
    return 0;
}

static int attack_oponent(t_list *list1, t_list *list2, t_player *player)
{
    int firsth;
    int firstl;
    int secondh;
    int secondl;

    firsth = ((int *) (list1->content))[0];
    firstl = ((int *) (list1->content))[1];
    secondh = ((int *) (list2->content))[0];
    secondl = ((int *) (list2->content))[1];

    if (if_closer(player, firsth, firstl) > if_closer(player, secondh, secondl))
        return 1;
    return 0;
}

t_list *choose_algo(t_list *list, t_player *player)
{
    t_list *result;

    draw_distance(player);
    if (have_contact(player))
    {
        player->star_to = 3;
    }
    if (player->star_to == -1) {
        result = choose_better(list, go_left, player);
    }
        else if(player->star_to == 1) {
        result = choose_better(list, go_right, player);

    }
    else {
        result = choose_better(list, attack_oponent, player);

    }
        return result;
}

