/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:30:11 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 20:47:44 by jebossue         ###   ########.fr       */
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

int		ft_issort(f_arg **list, int *array)
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

void	ft_pivotbv2(f_arg **list, int *array)
{
	d_arg	*tmp;
	int		i;
	int		j;
	int		tmp_nbr;

	i = 0;
	tmp = (*list)->begin_b;
	while (i < (*list)->size_b)
	{
		j = i + 1;
		while (j < (*list)->size_b)
		{
			if (array[i] > array[j])
			{
				tmp_nbr = array[i];
				array[i] = array[j];
				array[j] = tmp_nbr;
			}
			j++;
		}
		i++;
	}
	(*list)->pivotb = array[(*list)->size_b / 2];
	free(array);
}

void	ft_pivotb(f_arg **list)
{
	d_arg	*tmp;
	int		i;
	int		*array;

	if ((array = malloc((*list)->size_b * sizeof(int))) == NULL)
		return ;
	tmp = (*list)->begin_b;
	i = 0;
	while (tmp != (*list)->end_b)
	{
		array[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	array[i] = tmp->nbr;
	ft_pivotbv2(list, array);
}
