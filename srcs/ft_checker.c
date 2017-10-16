/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/16 21:42:21 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_doublelst(char *av, d_arg **pile_a, f_arg **list)
{
	d_arg	*tmp;

	if ((*pile_a)->next == NULL)
	{
		(*pile_a)->nbr = ft_atoi_long(av);
		(*pile_a)->next = *pile_a;
		return ;
	}
	tmp = *pile_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	
}

int		ft_createpile(d_arg **pile_a, d_arg **pile_b, f_arg **list)
{
	if ((*list = (f_arg *)malloc(sizeof(*list))) == NULL)
		return(0);
	if ((*pile_a = (d_arg *)malloc(sizeof(*pile_a))) == NULL)
		return(0);
	if ((*pile_b = (d_arg *)malloc(sizeof(*pile_b))) == NULL)
		return(0);
	(*pile_a)->next = NULL;
	(*pile_a)->prev = NULL;
	(*pile_a)->nbr = 0;
	(*pile_b)->next = NULL;
	(*pile_b)->prev = NULL;
	(*pile_b)->nbr = 0;
	(*list)->begin_a = *pile_a;
	(*list)->end_a = *pile_a;
	(*list)->begin_b = *pile_b;
	(*list)->end_b = *pile_b;
}

int	ft_check(h_arg arg, d_arg *pile_a, d_arg *pile_b)
{
	char	*line;
	int		instruction;
	f_arg	*list;
	char	**full_av;

	if (arg.ac < 2)
		return (0);
	if (ft_createpile(&pile_a, &pile_b, &list) == 0)
		return(0);
	while (arg.av)
	{
		full_av = ft_strsplit(arg.av[i], ' ');
		if (ft_isint(full_av) == 0)
		{
			free(full_av);
			return (0);
		}
		while (full_av)
		{
			ft_doublelst(*full_av, &pile_a, &pile_b);
			full_av++;
		}
		arg.av++;
	}
	/*
	if (arg.ac < 2 || ft_isint(arg.av) == 0 || ft_isdoublon(arg.av) == 0)
		return (0);
//	if ac == 2 return av;
	ft_createpile_a(arg, &pile_a, &list); //fct boolean if malloc fail
	ft_createpile_b(&pile_b, &list); //same
	ft_visual(pile_a, NULL, list);
	while (get_next_line(0, &line) == 1)
	{
		if ((instruction = ft_check_action(line)) == 0)
		{
			ft_free_pile_a(pile_a, list);
			ft_free_pile_b(pile_b, list);
			return (0);
		}
		ft_sort(&pile_a, &pile_b, instruction, &list);
		free(line);
	}
	ft_visual(pile_a, pile_b, list);
	printf("free a\n");
	ft_free_pile_a(pile_a, list);
	printf("free b\n");
	ft_free_pile_b(pile_b, list);
	free(list);
	list = NULL;
	line = NULL;*/
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
