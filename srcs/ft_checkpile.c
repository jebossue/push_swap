/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:15:25 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/06 18:48:49 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_checkpile_s(d_arg *list)
{
	if (list->next == NULL || list->next == list)
		return (0);
	return (1);
}

int	ft_checkpile_p(d_arg *list)
{
	if (!(list->next))
		return (0);
	return (1);
}

void	ft_adjustpile_b(d_arg **pile_b, f_arg **list)
{
	d_arg	*tmp;

	if ((*pile_b)->next == *pile_b)
	{
		(*list)->begin_b = NULL;
		(*list)->end_b = NULL;
		free(*pile_b);
	}
	else if ((*pile_b)->next == (*list)->end_b)
	{
		free(*pile_b);
		*pile_b = (*list)->end_b;
		(*list)->begin_b = (*list)->end_b;
		(*pile_b)->next = *pile_b;
		(*pile_b)->prev = *pile_b;
	}
	else
	{
		tmp = (*pile_b)->next;
		free(*pile_b);
		*pile_b = tmp;
		(*list)->begin_b = *pile_b;
		((*list)->end_b)->next = *pile_b;
		(*pile_b)->prev = (*list)->end_b;
	}
}

void	ft_adjustpile_a(d_arg **pile_a, f_arg **list)
{
	d_arg	*tmp;
	d_arg	*temp;

	if ((*pile_a)->next == *pile_a)
	{
		(*list)->begin_a = NULL;
		(*list)->end_a = NULL;
		free(*pile_a);
		*pile_a = NULL;
		if (*pile_a)
			printf("lol\n");
	}
	else if ((*pile_a)->next == (*list)->end_a)
	{
		temp = *pile_a;
		free(*pile_a);
		*pile_a = (*list)->end_a;
		(*list)->begin_a = (*list)->end_a;
		(*pile_a)->next = *pile_a;
		(*pile_a)->prev = *pile_a;
	}
	else
	{
		tmp = (*pile_a)->next;
		free(*pile_a);
		*pile_a = tmp;
		(*list)->begin_a = *pile_a;
		((*list)->end_a)->next = *pile_a;
		(*pile_a)->prev = (*list)->end_a;
	}
}
