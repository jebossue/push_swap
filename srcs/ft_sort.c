/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:33:35 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/27 20:30:34 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_sort(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{
	if (instruction >= 1 && instruction <= 3)
		ft_s(line, list_a, list_b, instruction);
/*	if (instruction >= 4 && instruction <= 5)
		ft_p(line, list_a, list_b, instruction);
	if (instruction >= 6 && instruction <= 8)
		ft_r(line, list_a, list_b, instruction);
	if (instruction >= 9 && instruction <= 11)
		ft_rr(line, list_a, list_b, instruction);*/
}

void	ft_s(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{
	(void)line;
	d_arg	*tmp_list;
	int		tmp_nbr;

	tmp_list = (*list_a)->begin;
	if (instruction == 1 || instruction == 3)
	{
		if (ft_checkpile_s(*list_a) == 0)
			return ;
		tmp_nbr = tmp_list->nbr;
		tmp_list->nbr = (tmp_list->next)->nbr;
		(tmp_list->next)->nbr = tmp_nbr;
	}
	tmp_list = (*list_b)->begin;
	if (instruction == 2 || instruction == 3)
	{
		if (ft_checkpile_s(*list_b) == 0)
			return ;
		tmp_nbr = tmp_list->nbr;
		tmp_list->nbr = (tmp_list->next)->nbr;
		(tmp_list->next)->nbr = tmp_nbr;
	}
}

void	ft_p(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{
	(void)line;
	d_arg	*tmp_list;
	d_arg	*tmp_new;
	int		tmp_nbr;

	tmp_list = (*list_b)->begin;
	if ((tmp_new = (d_arg *)malloc(sizeof(tmp_new))) == NULL)
		return ;
	if (instruction == 4)
	{
		if (ft_checkpile_p(*list_b) == 0)
			return ;
		tmp_new->nbr = ((*list_b)->begin)->nbr;
		tmp_new->next = (*list_a)->begin;
		tmp_new->prev = (*list_a)->end;
		if ((*list_a)->begin) //if pile_a existe
		{
			((*list_a)->begin)->prev = tmp_new;
			((*list_a)->end)->next = tmp_new;
		}
		(*list_a)->begin = tmp_new;
		if ((*list_b)->begin == ((*list_b)->end))
		{
			free((*list_b)->begin);
			free((*list_b)->end);
		}
		;
	}
}
/*
void	ft_r(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{

}

void	ft_rr(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{

}*/
