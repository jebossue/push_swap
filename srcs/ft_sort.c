/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:33:35 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/05 17:54:56 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_sort(d_arg **pile_a, d_arg **pile_b, int instruction, f_arg **list)
{
	(void)list;
	if (instruction >= 1 && instruction <= 3)
		ft_s(pile_a, pile_b, instruction, list);
/*	if (instruction == 4)
		ft_pa(pile_a, pile_b);
	if (instruction == 5)
		ft_pb(pile_a, pile_b);

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
/*
void	ft_pa(f_arg **list_a, f_arg **list_b)
{
	d_arg	*tmp_new;

	if (ft_checkpile_p(*list_b) == 0)
		return ;
	if ((tmp_new = (d_arg *)malloc(sizeof(tmp_new))) == NULL)
		return ;
	tmp_new->nbr = ((*list_b)->begin)->nbr;
	tmp_new->next = (*list_a)->begin;
	tmp_new->prev = (*list_a)->end;
	if (((*list_a)->begin)->next) //if pile_a existe
	{
		((*list_a)->begin)->prev = tmp_new;
		((*list_a)->end)->next = tmp_new;
	}
	(*list_a)->begin = tmp_new;
	ft_adjustpile(list_b);
	free (tmp_new);
}

void	ft_pb(f_arg **list_a, f_arg **list_b)
{
	d_arg	*tmp_new;

	if (ft_checkpile_p(*list_a) == 0)
		return ;
	if ((tmp_new = (d_arg *)malloc(sizeof(tmp_new))) == NULL)
		return ;
	tmp_new->nbr = ((*list_a)->begin)->nbr;
	tmp_new->next = (*list_b)->begin;
	tmp_new->prev = (*list_b)->end;
	if (((*list_b)->begin)->next) //if pile_b existe
	{
		((*list_b)->begin)->prev = tmp_new;
		((*list_b)->end)->next = tmp_new;
	}
	(*list_b)->begin = tmp_new;
	ft_adjustpile(list_a);
	free (tmp_new);
}


   void	ft_r(char *line, f_arg **list_a, f_arg **list_b, int instruction)
   {

   }

   void	ft_rr(char *line, f_arg **list_a, f_arg **list_b, int instruction)
   {

   }*/
