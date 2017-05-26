/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/05/26 17:45:05 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char **av)
{
	av++;
	
	if (/*get_next_line(0, av) != 1 ||*/ ac < 2 || ft_isint(av) == 0 /*||
			ft_isdoublon(av) == 0*/)
	{
		ft_printf("Error\n");
	}
/*	else
		ft_printf("OK\n");*/
	return (0);
}
