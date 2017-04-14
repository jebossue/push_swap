/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/04/14 15:06:33 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*int	ft_isint(char **av)
{
	long int nb;

	av++;
	while (*av)
	{
		nb = ft_atoi_long(*av);
		if ((nb == 0 && ft_strcmp(*av, "0") != 0) || (nb > 2147483648 ||
					nb < -2147483647))
			return (0);
		if (ft_isnbr(ft_atoi_long(*av)) == 0)
			return (0);
		av++;
	}
	return (1);
}*/

int	main(int ac, char **av)
{
	if (ac < 2 || ft_isint(av) == 0)
		ft_printf("Error");
	return (0);
}
