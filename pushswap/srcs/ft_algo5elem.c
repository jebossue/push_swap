/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo5elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:41:10 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/25 17:55:31 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_5elementsinb(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	i;

	while ((*list)->size_b > 5)
	{
		printf("size_b %d\n", (*list)->size_b);
		ft_pivotb(list);
		i = (*list)->size_b - (*list)->size_pivotb;
		printf("size_pivotb %d\n", (*list)->size_pivotb);
		printf("i %d\n", i);
		while (i != 0)
		{
			while (((*list)->begin_b)->nbr > (*list)->pivotb)
			{
				ft_pa(pile_a, pile_b, list);
				ft_visual(*pile_a, *pile_b,*list);
				i--;
			}
			if (i != 0)
			{
				ft_r(pile_a, pile_b, list, 7);
			}
		}
		ft_size(list);
		ft_visual(*pile_a, *pile_b, *list);
	}
}

void	ft_rb_or_rrb(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;
	int		max;
	int		position;
	int		i;

	i = 1;
	position = i;
	max = ((*list)->begin_b)->nbr;
	tmp = (*list)->begin_b;
	while (tmp != (*list)->end_b)
	{
		if (tmp->nbr > max)
		{
			max = tmp->nbr;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (tmp->nbr > max)
	{
		max = tmp->nbr;
		position = i;
	}
	if (position >= 3)
	{
		if (position == 5 || (position < 5 && (*list)->size_b == 5))
			ft_rr(pile_a, pile_b, list, 10);
		if (position == 4 || position < 4)
			ft_rr(pile_a, pile_b, list, 10);
		if (position == 3)
			ft_rr(pile_a, pile_b, list, 10);
	}
	if (position == 2)
		ft_r(pile_a, pile_b, list, 7);
	ft_visual(*pile_a, *pile_b, *list);
	ft_pa(pile_a, pile_b, list);
}

void	ft_fifthelem(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	totalmove;

	totalmove = (*list)->size_b;
	printf("move %d\n", totalmove);
	while ((*list)->size_b > 3)
	{
		ft_rb_or_rrb(list, pile_a, pile_b);
		ft_size(list);
		(*list)->elementsinb++;
	}
	ft_algothree(list, pile_a, pile_b);
	ft_visual(*pile_a, *pile_b, *list);
	while (totalmove != 0)
	{
		ft_r(pile_a, pile_b, list, 6);
		totalmove--;
	}
	ft_visual(*pile_a, *pile_b, *list);
}
