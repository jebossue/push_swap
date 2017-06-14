/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/14 19:40:02 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

/*void	ft_sort(b_arg *instruction, d_arg *pile_a, d_arg *pile_b, int ac)
{

}
*/
void	ft_createpile(d_arg *pile_a, d_arg *pile_b, char **av)
{
	if ((pile_b = (d_arg *)malloc(sizeof(*pile_b))) == NULL)
		return ;
	while (*av)
	{
		if ((pile_a = (d_arg *)malloc(sizeof(*pile_a))) == NULL)
			return ;
		pile_a->nbr = ft_atoi(*av);
		pile_a->next = pile_a;
		av++;
	}
	pile_a = NULL;
}

int	ft_check(int ac, char **av, b_arg *instruction)
{
	char	*line;

	line = NULL;
	if (ac < 2 || ft_isint(av) == 0 || ft_isdoublon(av) == 0)
		return (0);
	while (get_next_line(0, &line) == 1)
	{
		if ((instruction = (b_arg *)malloc(sizeof(*instruction))) == NULL)
			return (0);
		instruction->action = line;
		if (ft_check_action(instruction->action) != 0)
		{
			instruction->next = NULL;
			ft_free_list(instruction);
			return (0);
		}
		instruction->next = instruction;
	}
	instruction = NULL;
	return (1);
}

int	main(int ac, char **av)
{
	b_arg	*instruction;
	d_arg	*pile_a;
	d_arg	*pile_b;
	
	av++;
	instruction = NULL;
	pile_a = NULL;
	pile_b = NULL;
	if (ft_check(ac, av, instruction) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	printf("yo\n");
	ft_printf("%s\n", instruction->action);
	ft_createpile(pile_a, pile_b, av);
/*	while (pile_a)
	{
		printf("yo\n");
		ft_printf("%d\n", pile_a->nbr);
		pile_a = pile_a->next;
	}*/
//	ft_sort(instruction, pile_a, pile_b, ac);
//	ft_free_list(instructioni, pile_a, pile_b); include a la fin du prg
	return (0);
}
