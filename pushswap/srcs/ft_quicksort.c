/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:30:11 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/22 17:58:01 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_basicsort(int *array, f_arg **list)
{
	int	i;
	int	tmp;

	i = 0;
	while (i + 1 < (*list)->size_a)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = i - 2;
		}
		i++;
	}
	i = 0;
	return (array[((*list)->size_a / 2) - 1]);
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
