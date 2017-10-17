/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:33:35 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/17 21:10:24 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_sort(d_arg **pile_a, d_arg **pile_b, int instruction, f_arg **list)
{
	if (instruction >= 1 && instruction <= 3)
		ft_s(pile_a, pile_b, instruction, list);
	if (instruction == 4)
		ft_pa(pile_a, pile_b, list);
	if (instruction == 5)
		ft_pb(pile_a, pile_b, list);
	if (instruction >= 6 && instruction <= 8)
		ft_r(list, instruction);
	if (instruction >= 9 && instruction <= 11)
		ft_rr(list, instruction);
}

void	ft_s(d_arg **pile_a, d_arg **pile_b, int instruction, f_arg **list)
{
	int		tmp_nbr;
	(void)list;

	if (instruction == 1 || instruction == 3)
	{
		if (ft_checkpile_s(*pile_a) == 0)
			return ;
		tmp_nbr = (*pile_a)->nbr;
		(*pile_a)->nbr = ((*pile_a)->next)->nbr;
		((*pile_a)->next)->nbr = tmp_nbr;
	}
	if (instruction == 2 || instruction == 3)
	{
		if (ft_checkpile_s(*pile_b) == 0)
			return ;
		tmp_nbr = (*pile_b)->nbr;
		(*pile_b)->nbr = ((*pile_b)->next)->nbr;
		((*pile_b)->next)->nbr = tmp_nbr;
	}
}

void	ft_pa(d_arg **pile_a, d_arg **pile_b, f_arg **list)
{
	d_arg	*tmp_b_next;

	tmp_b_next = NULL;
	if (ft_checkpile_p(*pile_b) == 0)
		return ;
	if (*pile_b != (*list)->end_b)
		tmp_b_next = (*pile_b)->next;
	if ((*list)->end_a && *pile_a == (*list)->end_a)
	{
		(*pile_b)->next = *pile_a;
		(*pile_b)->prev = (*list)->end_b;
		(*pile_a)->prev = *pile_b;
		(*pile_a)->next = *pile_b;
		*pile_a = *pile_b;
	}
	else if ((*list)->end_a && *pile_a != (*list)->end_a)
	{
		(*pile_b)->next = *pile_a;
		(*pile_b)->prev = (*list)->end_a;
		(*pile_a)->prev = *pile_b;
		*pile_a = *pile_b;
	}
	else if (!(*list)->begin_a)
	{
		*pile_a = *pile_b;
		(*pile_a)->next = *pile_a;
		(*pile_a)->prev = *pile_a;
		(*list)->end_a = *pile_a;
	}
	(*list)->begin_a = *pile_a;
	ft_adjustpile_b(pile_b, list, tmp_b_next);
}

void	ft_pb(d_arg **pile_a, d_arg **pile_b, f_arg **list)
{
	d_arg	*tmp_a_next;

	tmp_a_next = NULL;
	if (ft_checkpile_p(*pile_a) == 0)
		return ;
	if (*pile_a != (*list)->end_a)
		tmp_a_next = (*pile_a)->next;
	if ((*list)->end_b && (*pile_b == (*list)->end_b))
	{
		(*pile_a)->next = *pile_b;
		(*pile_a)->prev = (*list)->end_a;
		(*pile_b)->prev = *pile_a;
		(*pile_b)->next = *pile_a;
		*pile_b = *pile_a;
	}
	else if ((*list)->end_b && (*pile_b != (*list)->end_b))
	{
		(*pile_a)->next = *pile_b;
		(*pile_a)->prev = (*list)->end_b;
		(*pile_b)->prev = *pile_a;
		*pile_b = *pile_a;
	}
	else if ((*list)->begin_b == NULL)
	{
		*pile_b = *pile_a;
		(*pile_b)->next = *pile_b;
		(*pile_b)->prev = *pile_b;
		(*list)->end_b = *pile_b;
	}
	(*list)->begin_b = *pile_b;
	ft_adjustpile_a(pile_a, list, &tmp_a_next);
}
