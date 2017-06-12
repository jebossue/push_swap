/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:28:36 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/12 18:39:30 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_free_list(b_arg *param)
{
	if (param == NULL)
		return ;
	ft_free_list(param->next);
	free(param);
}

int	ft_check_actionv3(char *str)
{
	char	*rrr;

	if (ft_strcmp(str, rrr = "rrr") == 0)
		return (0);
	return (1);
}

int	ft_check_actionv2(char *str)
{
	char	*ra;
	char	*rb;
	char	*rr;
	char	*rra;
	char	*rrb;

	if (ft_strcmp(str, ra = "ra") == 0)
		return (0);
	if (ft_strcmp(str, rb = "rb") == 0)
		return (0);
	if (ft_strcmp(str, rr = "rr") == 0)
		return (0);
	if (ft_strcmp(str, rra = "rra") == 0)
		return (0);
	if (ft_strcmp(str, rrb = "rrb") == 0)
		return (0);
	return (ft_check_actionv3(str));
}

int	ft_check_action(char *str)
{
	char	*sa;
	char	*sb;
	char	*ss;
	char	*pa;
	char	*pb;

	if (ft_strcmp(str, sa = "sa") == 0)
		return (0);
	if (ft_strcmp(str, sb = "sb") == 0)
		return (0);
	if (ft_strcmp(str, ss = "ss") == 0)
		return (0);
	if (ft_strcmp(str, pa = "pa") == 0)
		return (0);
	if (ft_strcmp(str, pb = "pb") == 0)
		return (0);
	return (ft_check_actionv2(str));
}
