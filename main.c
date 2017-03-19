/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:58:11 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/10 16:58:12 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "filler.h"

static void get_figure(t_player *player, char *data)
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

static int if_fit(t_player *player, int h , int l)
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
            if (player->figure[i][j] == '*' && player->map[i + h][j + l] == player->p)
                flag++;
            if (player->figure[i][j] == '*' && player->map[i + h][j + l] == player->oponent_p)
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
static int get_map(char *data, t_player *player)
{
    int  i;
    int j;

    i = 0;
    j = 0;
    get_next_line(0, &data);
    player->map_h = ft_atoi(&data[8]);
    player->map_l = ft_atoi(&data[8 + num_len(player->map_h)]);
    player->map = (char**)malloc(sizeof(char*) * player->map_h);
    free(data);
    get_next_line(0, &data);
    free(data);
    while(data[j] == ' ')
        j++;
    while (i < player->map_h)
    {
        get_next_line(0, &data);
        player->map[i] = ft_strsub(data, j, player->map_l);
        free(data);
        i++;
    }
    return 1;
}

static int find_place(t_player *player)
{
    int i;
    int j;
    t_list *variants;
    t_list *temp;

    variants = NULL;
    i = 0;
    j = 0;
    while(i < player->map_h - player->figure_h + 1)
    {
        while (j < player->map_l - player->figure_l + 1)
        {
            if (if_fit(player, i , j))
            {
                player->turn_res[0] = i;
                player->turn_res[1] = j;
                ft_lstadd_end(&variants, ft_lstnew(player->turn_res, sizeof(player->turn_res)));
            }
            j++;
        }
        j = 0;
        i++;
    }
    if (variants != NULL)
    {
        temp = variants;
        variants = choose_algo(variants, player);
        player->turn_res[0] = ((int *) variants->content)[0];
        player->turn_res[1] = ((int *) variants->content)[1];
        clear_list(temp);
    }else
    {
        ft_printf("cant solve");
    }
    return (1);
}

static void read_player(char *data, t_player *player)
{

    get_next_line(0, &data);
    if (player->p == 0) {
        if (!ft_strncmp(data, "$$$ exec p1", 11)) {
            player->p = 'O';
            player->oponent_p = 'X';
        }
            else {
            player->p = 'X';
            player->oponent_p = 'O';
        }
    }
    free(data);
}

int main(int argc, char **argv)
{
    argc = 0;
    argv = 0;


    char *data;

    data = 0;

   t_player *player;

    player = malloc(sizeof(t_player));
    player->p = 0;
    player->map_h = 0;
    player->map = 0;


    while(1)
    {
        if (player->p == 0)
            read_player(data, player);
        get_map(data, player);
        get_figure(player, data);
        find_start_point(player);
        find_place(player);
        ft_printf("%d ", player->turn_res[0]);
        ft_printf("%d\n", player->turn_res[1]);
        clear_struct(player);
    }
}

//$$$ exec p1 : [/nfs/2016/o/omotyliu/git/filler/filler]
//Plateau 15 17:
//01234567890123456
//000 .................
//001 .................
//002 .................
//003 .................
//004 .................
//005 .................
//006 .................
//007 .................
//008 ..O..............
//009 .................
//010 .................
//011 .................
//012 ..............X..
//013 .................
//014 .................
//Piece 2 2:
//*.
//**

