/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:09:13 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/18 17:58:52 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_visual(d_arg *pile_a, d_arg *pile_b, f_arg *list)
{
	d_arg	*tmp_a;
	d_arg	*tmp_b;

/*	(void)pile_a;
	(void)pile_b;
	tmp_a = list->begin_a;
	tmp_b = list->begin_b;*/
	tmp_a = pile_a;
	tmp_b = pile_b;
	printf("Pile_a : ");
	while (list->begin_a && tmp_a != list->end_a)
	{
		printf(" %d ->", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	if (list->begin_a)
		printf(" %d", tmp_a->nbr);
	printf("\nPile_b : ");
	while (list->begin_b && tmp_b != list->end_b)
	{
		printf(" %d ->", tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
	if (list->begin_b)
		printf(" %d", tmp_b->nbr);
	printf("\n");
}
