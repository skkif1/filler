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
    player->figure_h = atoi(&data[6]);
    player->figure_l = atoi(&data[6 + num_len(player->figure_h)]);
    player->figure = (char**)malloc(sizeof(char*) * player->figure_h);
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
            if (player->figure[i][j] == '*' && player->map[i + h][j + l] == 'O')
                flag++;
            if (player->figure[i][j] == '*' && player->map[i + h][j + l] == 'X')
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
    player->map_h = atoi(&data[8]);
    player->map_l = atoi(&data[8 + num_len(player->map_h)]);
    player->map = (char**)malloc(sizeof(char*) * player->map_h);
    get_next_line(0, &data);
    while(data[j] == ' ')
        j++;
    while (i < player->map_h)
    {
        get_next_line(0, &data);
        player->map[i] = ft_strsub(data, j, player->map_l);
        i++;
    }
    return 1;
}

static int find_place(t_player *player)
{
    int i;
    int j;
    t_list *variants;

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
        variants = choose_algo(variants, player);
        player->turn_res[0] = ((int *) variants->content)[0];
        player->turn_res[1] = ((int *) variants->content)[1];
    }else
    {
        ft_printf("cant solve");
    }
    return (1);
}

static int read_player(char *data, t_player *player)
{

        get_next_line(0, &data);
        if (player->p == 0)
        {
            if (!ft_strncmp(data, "$$$ exec p1", 11))
                player->p = 'O';
            else
                player->p = 'X';
            return 1;
        }
    return 0;
}



int main(int argc, char **argv)
{
    argc = 0;
    argv = 0;
    char *data;
    char *tmp;

    data = 0;
    t_player *player;

    tmp = ft_strnew(1);
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
    }
}

//$$$ exec p1 : [/nfs/2016/o/omotyliu/git/filler/filler]
//Plateau 24 40:
//0123456789012345678901234567890123456789
//000 OOOOOOOOOOOOOOOOOOOO....................
//001 OOOOOOOOOOOOOOOOOOOOOOOO................
//002 OOOOOOOOOOOOOOOOOOOOOOOOOOO.............
//003 OOOOOOOOOOOOOOOOOOOOOO..OO..............
//004 OOOOOO...O..OOOO....OOOOOOO.............
//005 O.OO.................O.OOOO.............
//006 .....................O..OOOO............
//007 .....................OOOO.O.............
//008 ........................................
//009 ........................................
//010 ......................X.................
//011 .....................XXXXXX.XXX.........
//012 ...................XXXXXXXX.XXX.........
//013 ..................XXXXXXXXXXXXX.........
//014 ..................XXXXXXXXXXXX..........
//015 ..................XXXXXXXXXXXX..........
//016 ..................XXXXXXXXXXXX..........
//017 ..................XXXXXXXXXXXX..........
//018 ..................XXXXXXXX.XXXX.........
//019 ...................xXXXXX..XXXXXXX......
//020 ..................xxXXXXX...XXX.........
//021 ...................xXXX.XX...XX.........
//022 ........................................
//023 ........................................
//Piece 4 6:
//......
//......
//*.....
//*.....
