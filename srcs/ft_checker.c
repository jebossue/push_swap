/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/16 18:11:24 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

/*void	ft_sort(char **av, char *line)
{
}*/

void	ft_createpile(char **av, d_arg **pile_a, d_arg *pile_b)
{
	d_arg	*tmp;

	if ((pile_b = (d_arg *)malloc(sizeof(*pile_b))) == NULL)
		return ;
	while (*av)
	{
		if ((tmp = (d_arg *)malloc(sizeof(*tmp))) == NULL)
			return ;
		tmp->nbr = ft_atoi(*av);
		if (!(*pile_a))
			*pile_a = tmp;
		else
			(*pile_a)->next = tmp;
		free(tmp);
		av++;
	}
	(*pile_a)->next = NULL;
}

int	ft_check(int ac, char **av, d_arg *pile_a, d_arg *pile_b)
{
	char	*line;
	d_arg	*tmp;

	line = NULL;
	if (ac < 2 || ft_isint(av) == 0 || ft_isdoublon(av) == 0)
		return (0);
	ft_createpile(av, &pile_a, pile_b);
	tmp = pile_a;
	while (pile_a)
	{
		printf("%d\n", tmp->nbr);
		printf("yo\n");
		tmp = tmp->next;
	}
	while (get_next_line(0, &line) == 1)
	{
		if (ft_check_action(line) != 0)
			return (0);
//		ft_sort(av, line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	d_arg	*pile_a;
	d_arg	*pile_b;

	av++;
	pile_a = NULL;
	pile_b = NULL;
	if (ft_check(ac, av, pile_a, pile_b) == 0)
	{
		ft_printf("Error\n");
		ft_free_list(pile_a);
		ft_free_list(pile_b);
		return (0);
	}
//	ft_free_list(instruction, pile_a, pile_b); include a la fin du prg
	return (0);
}
