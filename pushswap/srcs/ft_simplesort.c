/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:34:26 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 20:47:43 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_simplepivotv2(f_arg **list, int *array)
{
	d_arg	*tmp;
	int		i;
	int		j;
	int		tmp_nbr;

	i = 0;
	tmp = (*list)->begin_a;
	while (i < (*list)->size_a)
	{
		j = i + 1;
		while (j < (*list)->size_a)
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
	if ((*list)->size_a == 5)
		(*list)->pivot = array[1];
	if ((*list)->size_a == 4)
		(*list)->pivot = array[0];
	free(array);
}

void	ft_simplepivot(f_arg **list)
{
	d_arg	*tmp;
	int		i;
	int		*array;

	if ((array = malloc((*list)->size_a * sizeof(int))) == NULL)
		return ;
	tmp = (*list)->begin_a;
	i = 0;
	while (tmp != (*list)->end_a)
	{
		array[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	array[i] = tmp->nbr;
	ft_simplepivotv2(list, array);
}

void	ft_simpler_or_rr(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;

	tmp = (*list)->begin_a;
	(*list)->position_r = 0;
	(*list)->position_rr = 0;
	while (tmp->nbr > (*list)->pivot)
	{
		tmp = tmp->next;
		(*list)->position_r++;
	}
	tmp = (*list)->begin_a;
	while (tmp->nbr > (*list)->pivot)
	{
		tmp = tmp->prev;
		(*list)->position_rr++;
	}
	if ((*list)->position_r <= (*list)->position_rr)
	{
		while ((*list)->position_r != 0)
		{
			ft_r(pile_a, pile_b, list, 6);
			(*list)->position_r--;
		}
	}
	if ((*list)->position_r >= (*list)->position_rr)
	{
		while ((*list)->position_rr != 0)
		{
			ft_rr(pile_a, pile_b, list, 9);
			(*list)->position_rr--;
		}
	}
}

void	ft_simplesort(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	totalsize;

	totalsize = (*list)->size_a;
	ft_size(list);
	ft_simplepivot(list);
	while ((*list)->size_a > 3)
	{
		ft_simpler_or_rr(list, pile_a, pile_b);
		ft_pb(pile_a, pile_b, list);
		(*list)->size_a--;
	}
	ft_simplethree(list, pile_a, pile_b);
	if (totalsize == 5 || totalsize == 4)
	{
		if (totalsize == 5)
			ft_pa(pile_a, pile_b, list);
		ft_pa(pile_a, pile_b, list);
	}

}
