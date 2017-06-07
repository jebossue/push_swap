/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/07 16:59:02 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check(int ac, char **av)
{
	char	*line;

	line = NULL;
	if (ac < 2 || ft_isint(av) == 0 || ft_isdoublon(av) == 0)
		return (0);
	while (get_next_line(0, &line) == 1)
	{
		printf("phrase : %s\n", line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	av++;
	if (ft_check(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	printf("yo\n");
	return (0);
}
