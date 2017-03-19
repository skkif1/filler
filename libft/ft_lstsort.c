/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:06:51 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/04 16:06:55 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstsort(t_list *lst, void (*f)(t_list *elem, t_list *elem2))
{
	t_list	*temp;
	t_list	*second;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst;
	second = lst->next;
	while (temp)
	{
		while (second)
		{
			f(temp, second);
			second = second->next;
		}
		temp = temp->next;
		second = temp;
	}
}
