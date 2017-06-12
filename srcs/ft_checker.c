/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:18:18 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/12 19:30:31 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_check(int ac, char **av)
{
	b_arg	*param;
	char	*line;

	line = NULL;
	if (ac < 2 || ft_isint(av) == 0 || ft_isdoublon(av) == 0)
		return (0);
	while (get_next_line(0, &line) == 1)
	{
		if ((param = (b_arg *)malloc(sizeof(*param))) == NULL)
			return (0);
		param->action = line;
		if (ft_check_action(param->action) != 0)
		{
	printf("yo\n");
	//PBL ICI
			ft_free_list(param);
			return (0);
		}
		param = param->next;
	}
//	ft_sort(param, av);
	param = NULL;
	ft_free_list(param);
	return (1);
}

int	main(int ac, char **av)
{
	ft_printf("%d\n", av[2]);
	av++;
	if (ft_check(ac, av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (0);
}
