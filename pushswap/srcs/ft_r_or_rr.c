/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_or_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:23:10 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 20:47:48 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_putflags(f_arg **list)
{
	d_arg	*tmp;

	tmp = (*list)->begin_b;
	while (tmp != (*list)->end_b)
	{
		tmp->flag = tmp->flag + 1; 
		tmp = tmp->next;
	}
	tmp->flag = tmp->flag + 1; 
}

void	ft_r_or_rr_a(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_a;
	(*list)->position_r = 0;
	(*list)->position_rr = 0;
	while (tmp->nbr > (*list)->pivot)
	{
		tmp = tmp->next;
		(*list)->position_r++;
	}
	tmp = (*list)->begin_a;
	while (tmp->nbr > (*list)->pivot)
	{
		tmp = tmp->prev;
		(*list)->position_rr++;
	}
	if ((*list)->position_r <= (*list)->position_rr)
	{
		while ((*list)->position_r != 0)
		{
			ft_r(pile_a, pile_b, list, 6);
			(*list)->position_r--;
		}
	}
	if ((*list)->position_r >= (*list)->position_rr)
	{
		while ((*list)->position_rr != 0)
		{
			ft_rr(pile_a, pile_b, list, 9);
			(*list)->position_rr--;
		}
	}
}

void	ft_r_or_rr_b(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_b;
	(*list)->position_r = 0;
	(*list)->position_rr = 0;
	while (tmp->nbr < (*list)->pivotb)
	{
		tmp = tmp->next;
		(*list)->position_r++;
	}
	tmp = (*list)->begin_b;
	while (tmp->nbr < (*list)->pivotb)
	{
		tmp = tmp->prev;
		(*list)->position_rr++;
	}
	if ((*list)->position_r <= (*list)->position_rr)
	{
		while ((*list)->position_r != 0)
		{
			ft_r(pile_a, pile_b, list, 7);
			(*list)->position_r--;
		}
	}
	if ((*list)->position_r >= (*list)->position_rr)
	{
		while ((*list)->position_rr != 0)
		{
			ft_rr(pile_a, pile_b, list, 10);
			(*list)->position_rr--;
		}
	}
}
