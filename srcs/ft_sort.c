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
	d_arg	*tmp_a;
	d_arg	*tmp_b;
	int		tmp_nbr;

	tmp_a = (*list_a)->begin;
	tmp_b = (*list_b)->begin;
	if (instruction == 1 || instruction == 3)
	{
		tmp_nbr = tmp_a->nbr;
		tmp_a->nbr = (tmp_a->next)->nbr;
		(tmp_a->next)->nbr = tmp_nbr;
	}
	if (ft_checkpile_b() == 0)
		return ;
	if (instruction == 2 || instruction == 3)
	{
		tmp_nbr = tmp_b->nbr;
		tmp_b->nbr = (tmp_b->next)->nbr;
		(tmp_b->next)->nbr = tmp_nbr;
	}
}
/*
void	ft_p(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{

}

void	ft_r(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{

}

void	ft_rr(char *line, f_arg **list_a, f_arg **list_b, int instruction)
{

}*/
