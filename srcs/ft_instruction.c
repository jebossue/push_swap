/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:03:09 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/17 21:10:18 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int		ft_putelements(d_arg **pile_a, f_arg **list, h_arg arg)
{
	char	**full_av;
	int		i;
	int		j;

	i = 0;
	while (arg.av[i])
	{
		full_av = ft_strsplit(arg.av[i], ' ');
		if (ft_isint(full_av) == 0)
		{
			//free all full_av
			return (0);
		}
		j = 0;
		while (full_av[j])
		{
			ft_doublelst(full_av[j], pile_a, list);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_instruction(f_arg **list, d_arg **pile_a, d_arg **pile_b)
{
	char	*line;
	int		instruction;

	while (get_next_line(0, &line) == 1)
	{
		if ((instruction = ft_check_action(line)) == 0)
		{
			//free pile + list
			return ;
		}
		ft_sort(pile_a, pile_b, instruction, list);
		ft_visual(*pile_a, *pile_b, *list);
		free(line);
	}
	line = NULL;
}
