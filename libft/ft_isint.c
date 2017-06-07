/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:03:38 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/07 14:48:38 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char **av)
{
	long int nb;

	while (*av)
	{
		if (ft_isnbr(**av) == 0)
			return (0);
		nb = ft_atoi_long(*av);
		if ((nb == 0 && ft_strcmp(*av, "0") != 0) || (nb > 2147483647 ||
					nb <= -2147483648))
			return (0);
		if (ft_isnbr(ft_atoi_long(*av)) == 0)
			return (0);
		av++;
	}
	return (1);
}
