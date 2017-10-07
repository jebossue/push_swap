/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:09:13 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/06 18:48:53 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_visual(d_arg *pile_a, d_arg *pile_b, f_arg *list)
{
	d_arg	*tmp_a;
	d_arg	*tmp_b;

	tmp_a = pile_a;
	tmp_b = pile_b;
	if (tmp_a)
	{
		printf("pile_a : %d\n", tmp_a->nbr);
		while (tmp_a != list->end_a)
		{
			tmp_a = tmp_a->next;
			printf("pile_a : %d\n", tmp_a->nbr);
		}
	}
	printf("\n");
	if (tmp_b)
	{
		printf("pile_b : %d\n", tmp_b->nbr);
		while (tmp_b != list->end_b)
		{
			tmp_b = tmp_b->next;
			printf("pile_b : %d\n", tmp_b->nbr);
		}
	}
}
