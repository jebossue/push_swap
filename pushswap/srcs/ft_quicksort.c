/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:30:11 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/23 22:24:51 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_basicsort(int *array, f_arg **list)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	while (i < (*list)->size_a)
	{
		j = i + 1;
		while (j < (*list)->size_a)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	(*list)->pivot = array[((*list)->size_a / 2 - 1)];
	(*list)->size_pivot = (*list)->size_a / 2;
}

int	ft_issort(f_arg **list, int *array)
{
	d_arg	*tmp;
	int		i;

	tmp = (*list)->begin_a;
	i = 0;
	while (tmp != (*list)->end_a)
	{
		if (tmp->nbr != array[i])
			return (0);
		i++;
		tmp = tmp->next;
	}
	if (tmp->nbr != array[i])
		return (0);
	return (1);
}

int		ft_lastelem(f_arg **list)
{
	d_arg	*tmp;
	int		i;

	i = 0;
	tmp = (*list)->begin_a;
	while (tmp->nbr != (*list)->array[0])
	{
		tmp = tmp->next;
		i++;
	}
	i++;
	return (i);
}

void	ft_pivotb(f_arg **list)
{
	d_arg	*tmp;
	int		i;
	int		array[(*list)->size_b];
	int		j;

	tmp = (*list)->begin_b;
	i = 0;
	while (tmp != (*list)->end_b)
	{
		array[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	array[i] = tmp->nbr;
	i = 0;
	tmp = (*list)->begin_b;
	while (i < (*list)->size_b)
	{
		j = i + 1;
		while (j < (*list)->size_b)
		{
			if (array[i] > array[j])
			{
				tmp->nbr = array[i];
				array[i] = array[j];
				array[j] = tmp->nbr;
			}
			j++;
		}
		i++;
	}
	(*list)->pivotb = array[(*list)->size_b / 2 - 1];
	printf("puvotb%d\n", (*list)->pivotb);
}
/*
void	ft_putb(f_arg **list, int pivot, d_arg **pile_a, d_arg **pile_b)
{
	int		i;

	if ((*list)->i_pivot != (*list)->size_a)
		i = 5;
	else
		i = ft_lastelem(list);
	while (i != 0)
	{
		if (((*list)->begin_a)->nbr <= pivot)
		{
			ft_pb(pile_a, pile_b, list);
			i--;
			ft_printf("pb\n");
			ft_visual(*pile_a, *pile_b, *list);
		}
//		if rra ou ra
		ft_r(pile_a, pile_b, list, 6);
		ft_printf("ra\n");
		ft_visual(*pile_a, *pile_b, *list);
	}
}*/
