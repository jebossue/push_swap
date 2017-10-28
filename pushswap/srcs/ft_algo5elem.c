/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo5elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:41:10 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 19:57:50 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_algotwo(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	if ((*list)->size_b == 2)
	{
		if (((*list)->begin_b)->nbr > (((*list)->begin_b)->next)->nbr)
		{
			ft_pa(pile_a, pile_b, list);
			ft_pa(pile_a, pile_b, list);
			ft_r(pile_a, pile_b, list, 6);
			ft_r(pile_a, pile_b, list, 6);
		}
		else
		{
			ft_s(pile_a, pile_b, 2, list);
			ft_pa(pile_a, pile_b, list);
			ft_pa(pile_a, pile_b, list);
			ft_r(pile_a, pile_b, list, 6);
			ft_r(pile_a, pile_b, list, 6);
		}
	}
	else
	{
		ft_pa(pile_a, pile_b, list);
		ft_r(pile_a, pile_b, list, 6);
	}
}

void	ft_5elementsinb(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	i;

	while ((*list)->size_b > 5)
	{
		ft_pivotb(list);
		i = (*list)->size_b - (*list)->size_pivotb;
		while (i != 0)
		{
			while (((*list)->begin_b)->nbr > (*list)->pivotb)
			{
				ft_pa(pile_a, pile_b, list);
				i--;
			}
			if (i != 0)
			{
				ft_r(pile_a, pile_b, list, 7);
			}
		}
		ft_size(list);
	}
}

void	ft_rb_or_rrbv2(f_arg **list, d_arg **pile_a, d_arg **pile_b,
		int position)
{
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
	ft_pa(pile_a, pile_b, list);
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
	ft_rb_or_rrbv2(list, pile_a, pile_b, position);
}

void	ft_fifthelem(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	totalmove;

	totalmove = (*list)->size_b;
	while ((*list)->size_b > 3)
	{
		ft_rb_or_rrb(list, pile_a, pile_b);
		ft_size(list);
		(*list)->elementsinb++;
	}
	ft_algothree(list, pile_a, pile_b);
	while (totalmove != 0)
	{
		ft_r(pile_a, pile_b, list, 6);
		totalmove--;
	}
}
