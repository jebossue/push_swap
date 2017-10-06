/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:33:35 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/06 18:48:51 by jebossue         ###   ########.fr       */
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
/*
	if (instruction >= 6 && instruction <= 8)
		ft_r(line, list_a, list_b, instruction);
	if (instruction >= 9 && instruction <= 11)
		ft_rr(line, list_a, list_b, instruction);
		*/
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
	d_arg	*tmp;

	if (ft_checkpile_p(*pile_b) == 0)
		return ;
	if ((tmp = (d_arg *)malloc(sizeof(*tmp))) == NULL)
		return ;
	tmp->nbr = (*pile_b)->nbr;
	if ((*pile_a)->next)
	{
		(*pile_a)->prev = tmp;
		tmp->next = *pile_a;
		tmp->prev = (*list)->end_a;
		((*list)->end_a)->next = tmp;
	}
	else
	{
		(*list)->end_a = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	(*list)->begin_a = tmp;
	*pile_a = tmp;
	ft_adjustpile_b(pile_b, list);
}

void	ft_pb(d_arg **pile_a, d_arg **pile_b, f_arg **list)
{
	d_arg	*tmp;

	if (ft_checkpile_p(*pile_a) == 0)
		return ;
	if ((tmp = (d_arg *)malloc(sizeof(*tmp))) == NULL)
		return ;
	tmp->nbr = (*pile_a)->nbr;
	if ((*pile_b)->next)
	{
		(*pile_b)->prev = tmp;
		tmp->next = *pile_b;
		tmp->prev = (*list)->end_b;
		((*list)->end_b)->next = tmp;
	}
	else
	{
		(*list)->end_b = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	(*list)->begin_b = tmp;
	*pile_b = tmp;
	ft_adjustpile_a(pile_a, list);
}
/*

   void	ft_r(char *line, f_arg **list_a, f_arg **list_b, int instruction)
   {

   }

   void	ft_rr(char *line, f_arg **list_a, f_arg **list_b, int instruction)
   {

   }*/
