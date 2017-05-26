/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdoublon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:22:23 by jebossue          #+#    #+#             */
/*   Updated: 2017/05/26 17:23:09 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdoublon(char **av)
{
	int	i;
	int	nb;
	int	nbcomp;

	while (*av)
	{
	printf("av : %s\n", *av);
		nb = ft_atoi_long(*av);
		i = 0;
		av++;
//	printf("%s\n", ++(*av));
		while (*av)
		{
			i++;
			nbcomp = ft_atoi_long(*av);
			if (nb == nbcomp)
				return (0);
			av++;
		}
		av = av - i;
	}
	return (1);
}
