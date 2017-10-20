/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:55:35 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/20 18:26:44 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_free_pile_a(d_arg **param, f_arg **list)
{
	d_arg	*tmp;
	d_arg	*temp;

	tmp = *param;
	while (tmp && tmp != (*list)->end_a)
	{
		temp = tmp->next;
		free(tmp);
		tmp = temp;
	}
	if (tmp == (*list)->end_a)
		free(tmp);
}

void	ft_free_pile_b(d_arg **param, f_arg **list)
{
	d_arg	*tmp;
	d_arg	*temp;

	tmp = *param;
	while (tmp != (*list)->end_b)
	{
		temp = tmp->next;
		free(tmp);
		tmp = temp;
	}
	if (tmp == (*list)->end_b)
	{
		free(tmp);
	}
}

void	ft_free_full_av(char **full_av)
{
	int	i;

	i = 0;
	while (full_av[i])
	{
		free(full_av[i]);
		i++;
	}
	free(full_av);
}

void	ft_free_all(d_arg **pile_a, d_arg **pile_b, f_arg **list)
{
	ft_free_pile_a(pile_a, list);
	ft_free_pile_b(pile_b, list);
	free(*list);
}
