/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:48:54 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 19:58:19 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_separateb(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	i;

	i = 0;
	ft_size(list);
	while ((*list)->size_b > 5)
	{
		i = 0;
		ft_pivotb(list);
		if ((*list)->size_b % 2 != 0)
			(*list)->elementsinb = (*list)->size_b / 2 + 1;
		else
			(*list)->elementsinb = (*list)->size_b / 2;
		while (i < (*list)->elementsinb)
		{
			ft_r_or_rr_b(list, pile_a, pile_b);
			ft_pa(pile_a, pile_b, list);
			i++;
		}
		ft_size(list);
		ft_putflags(list);
	}
}

void	ft_pivot_bloc(f_arg **list, int flagelem)
{
	d_arg	*tmp;
	int		array[flagelem - 1];
	int		i;
	int		j;
	int		k;
	int		tmp_nbr;

	i = 0;
	tmp = (*list)->begin_a;
	while (flagelem != 0)
	{
		array[i] = tmp->nbr;
		flagelem--;
		tmp = tmp->next;
		i++;
	}
	k = i;
	i = 0;
	while (i < k)
	{
		j = i + 1;
		while (j < k)
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
	(*list)->pivot_bloc = array[k / 2];
}

void	ft_sort_rest(f_arg **list, d_arg **pile_a, d_arg **pile_b,
		int flag_pivot)
{
	int		flagelem;
	int		flag;
	d_arg	*tmp;
	int		i;
	int		rra_nbr;

	tmp = (*list)->begin_a;
	while (tmp->flag != flag_pivot)
	{
		flag = tmp->flag;
		flagelem = 0;
		while (tmp->flag == flag)
		{
			flagelem++;
			tmp = tmp->next;
		}
		if (flagelem > 5)
		{
			ft_pivot_bloc(list, flagelem);
			flagelem = flagelem / 2;
			i = 0;
			rra_nbr = 0;
			while (i < flagelem)
			{
				if (((*list)->begin_a)->nbr < (*list)->pivot_bloc)
				{
					ft_pb(pile_a, pile_b, list);
					i++;
				}
				else
				{
					ft_r(pile_a, pile_b, list, 6);
					rra_nbr++;
				}
			}
			while (rra_nbr != 0)
			{
				ft_rr(pile_a, pile_b, list, 9);
				rra_nbr--;
			}
		}
		else
		{
			if (ft_isalreadysort(list, flagelem) == 1)
			{
				while (flagelem != 0)
				{
					ft_r(pile_a, pile_b, list, 6);
					flagelem--;
				}
			}
			while (flagelem != 0)
			{
				ft_pb(pile_a, pile_b, list);
				flagelem--;
			}
		}
		ft_size(list);
		ft_separateb(list, pile_a, pile_b);
		ft_fifthelem(list, pile_a, pile_b);
		tmp = (*list)->begin_a;
	}
}
