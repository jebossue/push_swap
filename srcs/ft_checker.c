/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/21 19:43:33 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

/*void	ft_sort(char **av, char *line)
{

}*/

void	ft_doublelst(d_arg **pile_a, d_arg *new, f_arg **list, int ac)
{
	d_arg	*tmp;
	int		i;

	i = 0;
	if (!(*pile_a))
	{
		(*list)->begin = new;
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
		new->next = *pile_a;
}

void	ft_createpile(h_arg arg, d_arg **pile_a, d_arg *pile_b, f_arg *list)
{
	d_arg	*tmp;

	if ((list = (f_arg *)malloc(sizeof(*list))) == NULL)
		return ;
	if ((pile_b = (d_arg *)malloc(sizeof(*pile_b))) == NULL)
		return ;
	if ((list = (f_arg *)malloc(sizeof(*list))) == NULL)
		return ;
	while (*arg.av)
	{
		if ((tmp = (d_arg *)malloc(sizeof(*tmp))) == NULL)
			return ;
		tmp->nbr = ft_atoi(*arg.av);
		tmp->next = NULL;
		ft_doublelst(pile_a, tmp, &list, arg.ac);
		arg.av++;
	}
	free(tmp);
	tmp = NULL;
}

int	ft_check(h_arg arg, d_arg *pile_a, d_arg *pile_b, f_arg *list)
{
	char	*line;
	d_arg	*tmp;

	line = NULL;
	if (arg.ac < 2 || ft_isint(arg.av) == 0 || ft_isdoublon(arg.av) == 0)
		return (0);
	ft_createpile(arg, &pile_a, pile_b, list);
	tmp = pile_a;
	while (arg.ac - 1 != 0)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
		arg.ac--;
	}
	while (get_next_line(0, &line) == 1)
	{
		if (ft_check_action(line) != 0)
			return (0);
//		ft_sort(line, pile_a, pile_b, list);
	}
	return (1);
}

int	main(int ac, char **av)
{
	d_arg	*pile_a;
	d_arg	*pile_b;
	h_arg	arg;
	f_arg	*list;

	av++;
	pile_a = NULL;
	pile_b = NULL;
	list = NULL;
	arg.ac = ac;
	arg.av = av;
	if (ft_check(arg, pile_a, pile_b, list) == 0)
	{
		ft_printf("Error\n");
		ft_free_list(pile_a);
		ft_free_list(pile_b);
		return (0);
	}
	ft_printf("\n%d\n", ft_printf("%R\n"));
//	ft_free_list(instruction, pile_a, pile_b); include a la fin du prg
	return (0);
}
