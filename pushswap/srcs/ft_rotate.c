/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:23:37 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/20 20:29:24 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_rr(d_arg **pile_a, d_arg **pile_b, f_arg **list, int instruction)
{
	d_arg	*tmp;
	d_arg	*tmp_first;

	if ((*list)->end_a)
	{
		tmp = ((*list)->end_a)->prev;
		tmp_first = *pile_a;
	}
	if ((*list)->begin_a && (instruction == 9 || instruction == 11))
	{
		*pile_a = (*list)->end_a;
//		(*pile_a)->next = tmp_first;
//		(*pile_a)->prev = tmp;
		(*list)->begin_a = *pile_a;
		(*list)->end_a = tmp;
	}
	if ((*list)->end_b)
	{
		tmp = ((*list)->end_b)->prev;
		tmp_first = *pile_b;
	}
	if ((*list)->begin_b && (instruction == 10 || instruction == 11))
	{
		*pile_b = (*list)->end_b;
//		(*pile_b)->next = tmp_first;
//		(*pile_b)->prev = tmp;
		(*list)->begin_b = *pile_b;
		(*list)->end_b = tmp;
	}
}

void	ft_r(d_arg **pile_a, d_arg **pile_b, f_arg **list, int instruction)
{
	d_arg	*tmp;
	d_arg	*tmp_last;

	if ((*list)->end_a)
	{
		tmp = *pile_a;
		tmp_last = (*list)->end_a;
	}
	if ((*list)->begin_a && (instruction == 6 || instruction == 8))
	{
		*pile_a = (*pile_a)->next;
		(*list)->begin_a = *pile_a;
		(*list)->end_a = tmp;
	}
	if ((*list)->end_b)
	{
		tmp = (*pile_b);
		tmp_last = (*list)->end_b;
	}
	if ((*list)->begin_b && (instruction == 7 || instruction == 8))
	{
		*pile_b = (*pile_b)->next;
		(*list)->begin_b = *pile_b;
		(*list)->end_b = tmp;
	}
}
