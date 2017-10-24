/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo5elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:41:10 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/24 18:48:57 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_rb_or_rrb(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	d_arg	*tmp;
	int		max;
	int		position;
	int		i;

	i = 1;
	max = ((*list)->begin_b)->nbr;
	tmp = (*list)->begin_b;
	while (tmp != (*list)->end_b)
	{
		if (tmp->nbr > max)
		{
			max = tmp->nbr;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (tmp->nbr > max)
	{
		max = tmp->nbr;
		position = i;
		printf("position %d\n", position);
		printf("max %d\n", max);
	}
	if (position >= 3)
	{
		if (position == 5 || (position < 5 && (*list)->size_b == 5))
			ft_rr(pile_a, pile_b, list, 10);
		if (position == 4 || position < 4)
			ft_rr(pile_a, pile_b, list, 10);
		if (position == 3)
			ft_rr(pile_a, pile_b, list, 10);
	}
	if (position == 2 || position < 2)
		ft_r(pile_a, pile_b, list, 7);
	if (position == 1)
		ft_r(pile_a, pile_b, list, 7);
	ft_visual(*pile_a, *pile_b, *list);
	ft_pa(pile_a, pile_b, list);
}

void	ft_fifthelem(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	int	totalmove;

	totalmove = (*list)->size_b;
	while ((*list)->size_b > 3)
	{
		ft_rb_or_rrb(list, pile_a, pile_b);
		ft_size(list);
	}
	ft_algothree(list, pile_a, pile_b);
	ft_visual(*pile_a, *pile_b, *list);
	while (totalmove != 0)
	{
		ft_r(pile_a, pile_b, list, 6);
		totalmove--;
	}
	ft_visual(*pile_a, *pile_b, *list);
}
