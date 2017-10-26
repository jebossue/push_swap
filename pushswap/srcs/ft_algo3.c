/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:57:22 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/26 21:46:20 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_papapav2(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_b;
	if (tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr >
			((tmp->next)->next)->nbr)
	{
		ft_s(pile_a, pile_b, 2, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		return ;
	}
	else if (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr >
			((tmp->next)->next)->nbr)
	{
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
	}
}

void	ft_papapa(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_b;
	if (tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr >
			((tmp->next)->next)->nbr && tmp->nbr < ((tmp->next)->next)->nbr)
	{
		ft_r(pile_a, pile_b, list, 7);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		return ;
	}
	else if (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr)
	{
		ft_rr(pile_a, pile_b, list, 10);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
		return ;
	}
	ft_papapav2(list, pile_a, pile_b);
}

void	ft_crease(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
		ft_rr(pile_a, pile_b, list, 10);
		ft_pa(pile_a, pile_b, list);
		ft_s(pile_a, pile_b, 2, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
}

void	ft_lastthree(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
		ft_pa(pile_a, pile_b, list);
		ft_s(pile_a, pile_b, 2, list);
		ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
}

void	ft_algothree(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_b;
	if (!((tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr && tmp->nbr < ((tmp->next)->next)->nbr)
			|| (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr
				< ((tmp->next)->next)->nbr && tmp->nbr >
				((tmp->next)->next)->nbr)))
	{
		ft_papapa(list, pile_a, pile_b);
	}
	else if (tmp->nbr < (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr)
		ft_crease(list, pile_a, pile_b);
	else if (tmp->nbr > (tmp->next)->nbr && (tmp->next)->nbr <
			((tmp->next)->next)->nbr)
		ft_lastthree(list, pile_a, pile_b);
}
