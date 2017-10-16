/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:09:13 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/16 21:42:12 by jebossue         ###   ########.fr       */
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
	printf("Pile_a : ");
	if (list->begin_a)
	{
		printf("pile_a : %d ->", tmp_a->nbr);
//		printf("pile_a : %p\n", tmp_a);
		while (tmp_a != list->end_a)
		{
			tmp_a = tmp_a->next;
			printf(" %d ->", tmp_a->nbr);
//			printf("pile_a : %p\n", tmp_a);
		}
	}
	printf("\nPile_b : ");
	if (list->begin_b)
	{
		printf("%d ->", tmp_b->nbr);
		while (tmp_b != list->end_b)
		{
			tmp_b = tmp_b->next;
			printf(" %d ->", tmp_b->nbr);
		}
	}
	printf("\n");
}
