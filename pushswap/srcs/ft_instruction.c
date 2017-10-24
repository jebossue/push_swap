/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:03:09 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/24 21:29:38 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int		ft_putelements(d_arg **pile_a, f_arg **list, h_arg arg)
{
	char	**full_av;
	int		i;
	int		j;

	i = 0;
	while (arg.av[i])
	{
		full_av = ft_strsplit(arg.av[i], ' ');
		if (ft_isint(full_av) == 0)
		{
			ft_free_full_av(full_av);
			return (0);
		}
		j = 0;
		while (full_av[j])
		{
			ft_doublelst(full_av[j], pile_a, list);
			j++;
		}
		i++;
		ft_free_full_av(full_av);
	}
	return (1);
}

void	ft_size(f_arg **list)
{
	d_arg	*tmp;

	(*list)->size_a = 0;
	(*list)->size_b = 0;
	tmp = (*list)->begin_a;
	while (tmp != (*list)->end_a)
	{
		tmp = tmp->next;
		(*list)->size_a++;
	}
	(*list)->size_a++;
	tmp = (*list)->begin_b;
	while (tmp != (*list)->end_b)
	{
		tmp = tmp->next;
		(*list)->size_b++;
	}
	(*list)->size_b++;

}

void	ft_pivot(f_arg **list)
{
	d_arg	*tmp;
	int		*array;
	int		i;

	if ((array = malloc((*list)->size_a * sizeof(int))) == NULL)
		return ;// NEED TO FREE THIS
	tmp = (*list)->begin_a;
	i = 0;
	while (tmp != (*list)->end_a)
	{
		array[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	array[i] = tmp->nbr;
	(*list)->array = array;
	ft_basicsort((*list)->array, list);
	free(array);
}

void	ft_quicksort(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	i;

	i = 0;
	ft_pivot(list);
	while (i < (*list)->size_pivot)
	{
		while (((*list)->begin_a)->nbr <= (*list)->pivot)
		{
			ft_pb(pile_a, pile_b, list);
			ft_visual(*pile_a, *pile_b, *list);
			i++;
		}
		if (i != (*list)->size_pivot)
		{
			ft_r(pile_a, pile_b, list, 6);
		}
	}
	ft_size(list);
	while ((*list)->size_b > 5)
	{
		i = 0;
			printf("begin_b%d\n", ((*list)->begin_b)->nbr);
		ft_pivotb(list);
			printf("begin_b%d\n", ((*list)->begin_b)->nbr);
		while (i < (*list)->size_pivotb)
		{
			while (((*list)->begin_b)->nbr > (*list)->pivotb)
			{
				ft_pa(pile_a, pile_b, list);
				ft_visual(*pile_a, *pile_b,*list);
				i++;
			}
			if (i < (*list)->size_pivotb)
			{
				ft_r(pile_a, pile_b, list, 7);
			}
		}
		ft_size(list);
		ft_visual(*pile_a, *pile_b, *list);
	}
	ft_fifthelem(list, pile_a, pile_b);
/*	while (((*list)->begin_a)->nbr <= (*list)->pivot)
		ft_pb(pile_a, pile_b, list);*/

}

void	ft_algo(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	ft_size(list);
	if ((*list)->size_a > 5)
		ft_quicksort(list, pile_a, pile_b);
//	else
//		ft_exception(list);
}
