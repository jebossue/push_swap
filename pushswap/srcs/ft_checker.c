/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/27 14:02:28 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_doublelst(char *av, d_arg **pile_a, f_arg **list)
{
	d_arg	*tmp;
	d_arg	*new;

	if ((*list)->begin_a == NULL)
	{
		(*pile_a)->nbr = ft_atoi_long(av);
		(*pile_a)->next = *pile_a;
		(*pile_a)->prev = *pile_a;
		(*list)->begin_a = *pile_a;
		(*list)->end_a = *pile_a;
		return ;
	}
	tmp = *pile_a;
	while (tmp != (*list)->end_a)
		tmp = tmp->next;
	if ((new = (d_arg *)malloc(sizeof(*new))) == NULL)
		return ;
	new->nbr = ft_atoi_long(av);
	new->prev = tmp;
	new->next = (*list)->begin_a;
	tmp->next = new;
	(*list)->end_a = new;
	(*pile_a)->prev = new;
}

int		ft_createpile(d_arg **pile_a, d_arg **pile_b, f_arg **list)
{
	if ((*list = (f_arg *)malloc(sizeof(f_arg))) == NULL)
		return (0);
	if ((*pile_a = (d_arg *)malloc(sizeof(d_arg))) == NULL)
		return (0);
	if ((*pile_b = (d_arg *)malloc(sizeof(d_arg))) == NULL)
		return (0);
	(*pile_a)->next = NULL;
	(*pile_a)->prev = NULL;
	(*pile_a)->nbr = 0;
	(*pile_b)->next = NULL;
	(*pile_b)->prev = NULL;
	(*pile_b)->nbr = 0;
	(*list)->begin_a = NULL;
	(*list)->end_a = NULL;
	(*list)->begin_b = NULL;
	(*list)->end_b = NULL;
	(*list)->size_a = 0;
	(*list)->elementsinb = 0;
	(*list)->array = NULL;
	(*list)->size_pivot = 0;
	(*list)->size_b = 0;
	(*list)->pivot = 0;
	(*list)->pivotb = 0;
	ft_createpilev2(pile_a, pile_b, list);
	return (1);
}

int		ft_isdoublonlst(f_arg *lst)
{
	int		nbr;
	int		nbr_comp;
	d_arg	*tmp;
	d_arg	*tmp_first;

	tmp_first = lst->begin_a;
	while (tmp_first != lst->end_a)
	{
		nbr = tmp_first->nbr;
		tmp_first = tmp_first->next;
		tmp = tmp_first;
		while (tmp != lst->end_a)
		{
			nbr_comp = tmp->nbr;
			if (nbr == nbr_comp || nbr == ((lst)->end_a)->nbr)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		ft_check(h_arg arg, d_arg *pile_a, d_arg *pile_b)
{
	f_arg	*list;

	if (ft_createpile(&pile_a, &pile_b, &list) == 0)
	{
		ft_free_all(&pile_a, &pile_b, &list);
		return (0);
	}
	if (ft_strcmp(arg.av[0], "-v") == 0)
		list->option = 1;
	if (ft_putelements(&pile_a, &list, arg) == 0)
	{
		ft_free_all(&pile_a, &pile_b, &list);
		return (0);
	}
	if (ft_isdoublonlst(list) == 0)
	{
		ft_free_all(&pile_a, &pile_b, &list);
		return (0);
	}
	ft_algo(&list, &pile_a, &pile_b);
	ft_free_all(&pile_a, &pile_b, &list);
	return (1);
}

int		main(int ac, char **av)
{
	d_arg	*pile_a;
	d_arg	*pile_b;
	h_arg	arg;

	av++;
	pile_a = NULL;
	pile_b = NULL;
	arg.ac = ac;
	arg.av = av;
	if (ac < 2)
		return (0);
	if (ft_check(arg, pile_a, pile_b) == 0)
		ft_printf("Error\n");
	return (0);
}
