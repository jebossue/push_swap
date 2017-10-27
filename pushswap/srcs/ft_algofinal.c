/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:48:54 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/27 21:38:21 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_pivot_bloc(f_arg **list, int flagelem)
{
	d_arg	*tmp;
	int		array[flagelem - 1];
	int		i;

	i = 0;
	tmp = (*list)->begin_a;
	while (flagelem != 0)
	{
		array[i] = tmp->nbr;
		printf("array %d\n", array[i]);
		flagelem--;
		tmp = tmp->next;
		i++;
	}
	(*list)->pivot_bloc = array[i / 2];
}

void	ft_sort_rest(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int		flagelem;
	int		flag;
	d_arg	*tmp;
	(void)pile_a;
	(void)pile_b;

	flagelem = 0;
	tmp = (*list)->begin_a;
	while (tmp->flag != 0)
	{
		flag = tmp->flag;
		while (tmp->flag == flag)
		{
			flagelem++;
			tmp = tmp->next;
		}
		printf("flagelem %d\n", flagelem);
		while (flagelem > 5)
		{
			usleep(100000);
			ft_pivot_bloc(list, flagelem);
		}
	}
}
