/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/23 18:55:03 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_doublelst(d_arg **pile_a, d_arg *new, f_arg **list_a, int ac)
{
	d_arg	*tmp;
	int		i;

	i = 0;
	if (!(*pile_a))
	{
		(*list_a)->begin = new;
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
		(*list_a)->end = new;
	}
}

void	ft_createpile_a(h_arg arg, d_arg **pile_a, f_arg **list_a)
{
	d_arg	*tmp;

	if ((*list_a = (f_arg *)malloc(sizeof(*list_a))) == NULL)
		return ;
	if ((*pile_a = (d_arg *)malloc(sizeof(*pile_a))) == NULL)
		return ;
	while (*arg.av)
	{
		if ((tmp = (d_arg *)malloc(sizeof(*tmp))) == NULL)
			return ;
		tmp->nbr = ft_atoi(*arg.av);
		tmp->next = NULL;
		ft_doublelst(pile_a, tmp, list_a, arg.ac);
		arg.av++;
	}
	free(tmp);
	tmp = NULL;
}

void	ft_createpile_b(h_arg arg, d_arg **pile_b, f_arg **list_b)
{
	(void)arg;
	if ((*pile_b = (d_arg *)malloc(sizeof(*pile_b))) == NULL)
		return ;
	(*pile_b)->nbr = 0;
	if ((*pile_b)->next == NULL)
		printf("yo\n");
	if ((*list_b = (f_arg *)malloc(sizeof(*list_b))) == NULL)
		return ;
}

int	ft_check(h_arg arg, d_arg *pile_a, d_arg *pile_b)
{
	char	*line;
//	d_arg	*tmp;
	int		instruction;
	f_arg	*list_a;
	f_arg	*list_b;

	line = NULL;
	list_a = NULL;
	list_b = NULL;
	if (arg.ac < 2 || ft_isint(arg.av) == 0 || ft_isdoublon(arg.av) == 0)
		return (0);
//	ft_createpile_a(arg, &pile_a, &list_a);
//	ft_createpile_b(arg, &pile_b, &list_b);
/*	tmp = list->end;
	while (arg.ac - 1 != 0)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->prev;
		arg.ac--;
	}*/
	printf("yo\n");
	while (get_next_line(0, &line) == 1)
	{
		printf("%s\n", line);
		if ((instruction = ft_check_action(line)) == 0)
			return (0);
		printf("%d\n", instruction);
//		ft_sort(line, &list_a, &list_b, instruction);
	}
	ft_free_list(list_a);
	ft_free_list(list_b);
	ft_free_pile(pile_a);
	ft_free_pile(pile_b);
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
		ft_free_pile(pile_a);
		ft_free_pile(pile_b);
		return (0);
	}
/*	ft_free_list(list);
	ft_free_list(pile_a);
	ft_free_list(pile_b);// a include ds ft_check ou envoye adresse*/
	return (0);
}
