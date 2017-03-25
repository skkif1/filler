/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:41:36 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/10 18:41:38 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/ft_printf.h"

typedef struct	s_player
{
	char	p;
	char	oponent_p;
	int		map_h;
	int		map_l;
	char	**map;
	int		figure_h;
	int		figure_l;
	char	**figure;
	int		turn_res[2];
	int		star_to;
}				t_player;

int				num_len(int num);
t_list			*choose_algo(t_list *list, t_player *player);
void			find_start_point(t_player *player);
void			draw_distance(t_player *player);
int				if_closer(t_player *player, int h, int l);
int				have_contact(t_player *player);
void			clear_struct(t_player *player);
void			clear_list(t_list *list);
void			find_place(t_player *player);
void			calculate(t_player *player, t_list *list);
#endif
