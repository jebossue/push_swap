/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:15:25 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/17 21:10:26 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_checkpile_s(d_arg *list)
{
	if (list && (list->next == NULL || list->next == list))
		return (0);
	return (1);
}

int	ft_checkpile_p(d_arg *list)
{
	if (!(list))
		return (0);
	return (1);
}

void	ft_adjustpile_b(d_arg **pile_b, f_arg **list, d_arg *tmp_b_next)
{
	if (!tmp_b_next)
	{
		*pile_b = NULL;
		(*list)->begin_b = NULL;
		(*list)->end_b = NULL;
	}
	else if (tmp_b_next)
	{
		*pile_b = tmp_b_next;
		(*list)->begin_b = *pile_b;
		if (tmp_b_next == (*list)->end_b)
		{
			(*pile_b)->next = *pile_b;
			(*pile_b)->prev = *pile_b;
			(*list)->end_b = *pile_b;
		}
		else
			(*pile_b)->prev = (*list)->end_b;
	}
}

void	ft_adjustpile_a(d_arg **pile_a, f_arg **list, d_arg **tmp_a_next)
{	
	if (!(*tmp_a_next))
	{
		*pile_a = NULL;
		(*list)->begin_a = NULL;
		(*list)->end_a = NULL;
	}
	else if ((*tmp_a_next))
	{
		*pile_a = *tmp_a_next;
		(*list)->begin_a = *pile_a;
		if ((*tmp_a_next) == (*list)->end_a)
		{
			(*pile_a)->next = *pile_a;
			(*pile_a)->prev = *pile_a;
			(*list)->end_a = *pile_a;
		}
		else
			(*pile_a)->prev = (*list)->end_a;
	}
}
