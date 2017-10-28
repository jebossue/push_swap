/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplethree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:58:41 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 20:27:45 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_simplepapapav2(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_a;
	if (tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr >
			((tmp->next)->next)->nbr)
	{
		ft_rr(pile_a, pile_b, list, 9);
		return ;
	}
	else if (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr >
			((tmp->next)->next)->nbr)
	{
		ft_s(pile_a, pile_b, 1, list);
		ft_rr(pile_a, pile_b, list, 9);
	}
}

void	ft_simplepapapa(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_a;
	if (tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr >
			((tmp->next)->next)->nbr && tmp->nbr < ((tmp->next)->next)->nbr)
	{
		ft_r(pile_a, pile_b, list, 6);
		ft_s(pile_a, pile_b, 1, list);
		ft_rr(pile_a, pile_b, list, 9);
		return ;
	}
	else if (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr)
	{
		ft_s(pile_a, pile_b, 1, list);
		return ;
	}
	ft_simplepapapav2(list, pile_a, pile_b);
}

void	ft_simplelastthree(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	ft_r(pile_a, pile_b, list, 6);
}

void	ft_simplethree(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_a;
	if (tmp == NULL)
		return ;
	if (!((tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr && tmp->nbr < ((tmp->next)->next)->nbr)
			|| (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr
				< ((tmp->next)->next)->nbr && tmp->nbr >
				((tmp->next)->next)->nbr)))
	{
		ft_simplepapapa(list, pile_a, pile_b);
	}
	else if (tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr)
		return ;
	else if (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr)
		ft_simplelastthree(list, pile_a, pile_b);
}
