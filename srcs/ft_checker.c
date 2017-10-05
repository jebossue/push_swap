/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/05 17:54:52 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_doublelst(d_arg **pile_a, d_arg *new, f_arg **list, int ac)
{
	d_arg	*tmp;
	int		i;

	i = 0;
	if (!(*pile_a))
	{
		(*list)->begin_a = new;
		(*list)->end_a = new;
		*pile_a = new;
		return ;
	}
	tmp = *pile_a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = new;
	new->prev = tmp;
	if (i == ac - 3)
	{
		new->next = *pile_a;
		(*list)->end_a = new;
	}
}

void	ft_createpile_a(h_arg arg, d_arg **pile_a, f_arg **list)
{
	d_arg	*tmp;

	if ((*list = (f_arg *)malloc(sizeof(*list))) == NULL)
		return ;
	if ((*pile_a = (d_arg *)malloc(sizeof(*pile_a))) == NULL)
		return ;
	*pile_a = NULL;
	while (*arg.av)
	{
		if ((tmp = (d_arg *)malloc(sizeof(*tmp))) == NULL)
			return ;
		tmp->nbr = ft_atoi(*arg.av);
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_doublelst(pile_a, tmp, list, arg.ac);
		arg.av++;
	}
	free(tmp);
	tmp = NULL;
}

void	ft_createpile_b(d_arg **pile_b, f_arg **list)
{
	if ((*pile_b = (d_arg *)malloc(sizeof(*pile_b))) == NULL)
		return ;
	(*pile_b)->next = NULL;
	(*pile_b)->prev = NULL;
	(*list)->begin_b = NULL;
	(*list)->end_b = NULL;
}

int	ft_check(h_arg arg, d_arg *pile_a, d_arg *pile_b)
{
	char	*line;
	d_arg	*tmp;
	int		instruction;
	f_arg	*list;

	instruction = arg.ac;
	line = NULL;
	list = NULL;
	if (arg.ac < 2 || ft_isint(arg.av) == 0 || ft_isdoublon(arg.av) == 0)
		return (0);
//	if ac == 2 return av;
	ft_createpile_a(arg, &pile_a, &list);
	ft_createpile_b(&pile_b, &list);
	tmp = pile_a;
	while (instruction - 1 != 0)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
		instruction--;
	}
	while (get_next_line(0, &line) == 1)
	{
		if ((instruction = ft_check_action(line)) == 0)
		{
			ft_free_pile_a(pile_a, list);
			ft_free_pile_b(pile_b, list);
			return (0);
		}
		ft_sort(&pile_a, &pile_b, instruction, &list);
	}
	tmp = pile_a;
	while (tmp != list->end_a)
	{
		printf("list_a:%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("list_a %d\n", tmp->nbr);
	printf("listend%p\n", list->end_a);
	printf("pilend%p\n", pile_a->next);
	ft_free_pile_a(pile_a, list);
	printf("freepileb\n");
	free(pile_b);
//	ft_free_pile_b(pile_b, list);
	free(list);
	return (1);
}

int	main(int ac, char **av)
{
	d_arg	*pile_a;
	d_arg	*pile_b;
	h_arg	arg;

	av++;
	pile_a = NULL;
	pile_b = NULL;
	arg.ac = ac;
	arg.av = av;
	if (ft_check(arg, pile_a, pile_b) == 0)
	{
		ft_printf("Error\n");
//		ft_free_pile(pile_a); 
//		ft_free_pile(pile_b);
		return (0);
	}
/*	ft_free_list(list);
	ft_free_list(pile_a);
	ft_free_list(pile_b);// a include ds ft_check ou envoye adresse*/
	while (1);
	return (0);
}
