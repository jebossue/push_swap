/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofinal2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:05:19 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 19:58:16 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_isalreadysort(f_arg **list, int flagelem)
{
	d_arg	*tmp;
	int		i;

	i = 0;
	tmp = (*list)->begin_a;
	while (i < flagelem)
	{
		if (tmp->nbr > (tmp->next)->nbr)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
