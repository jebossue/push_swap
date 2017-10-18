/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:28:36 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/18 17:59:09 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_check_actionv2(char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		return (6);
	if (ft_strcmp(str, "rb") == 0)
		return (7);
	if (ft_strcmp(str, "rr") == 0)
		return (8);
	if (ft_strcmp(str, "rra") == 0)
		return (9);
	if (ft_strcmp(str, "rrb") == 0)
		return (10);
	if (ft_strcmp(str, "rrr") == 0)
		return (11);
	return (0);
}

int	ft_check_action(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	if (ft_strcmp(str, "sb") == 0)
		return (2);
	if (ft_strcmp(str, "ss") == 0)
		return (3);
	if (ft_strcmp(str, "pa") == 0)
		return (4);
	if (ft_strcmp(str, "pb") == 0)
		return (5);
	return (ft_check_actionv2(str));
}
