/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:23:37 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/17 19:37:06 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_r(f_arg **list, int instruction)
{
	d_arg	*tmp;

	tmp = (*list)->end_a;
	if ((*list)->begin_a && (instruction == 6 || instruction == 8))
	{
		(*list)->end_a = ((*list)->end_a)->prev;
		(*list)->begin_a = tmp;
	}
	tmp = (*list)->end_b;
	if ((*list)->begin_b && (instruction == 7 || instruction == 8))
	{
		(*list)->end_b = ((*list)->end_b)->prev;
		(*list)->begin_b = tmp;
	}
}

void	ft_rr(f_arg **list, int instruction)
{
	d_arg	*tmp;

	tmp = (*list)->begin_a;
	if ((*list)->begin_a && (instruction == 9 || instruction == 11))
	{
		(*list)->end_a = (*list)->begin_a;
		(*list)->begin_a = tmp->next;
	}
	tmp = (*list)->begin_b;
	if ((*list)->begin_b && (instruction == 10 || instruction == 11))
	{
		(*list)->end_b = tmp;
		(*list)->begin_b = tmp->next;
	}
}
