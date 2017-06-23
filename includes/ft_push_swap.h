/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:32:44 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/23 18:54:59 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H

# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct	c_arg
{
	int				nbr;
	struct c_arg	*next;
	struct c_arg	*prev;
}				d_arg;

typedef struct	e_arg
{
	struct c_arg	*begin;
	struct c_arg	*end;
}				f_arg;

typedef struct	g_arg
{
	int		ac;
	char	**av;
}				h_arg;

int			ft_isint(char **av);
int			ft_isdoublon(char **av);
int			get_next_line(const int fd, char **line);
int			ft_strarraycmp(char *str, char **rule);
void		ft_free_list(f_arg *param);
void		ft_free_pile(d_arg *param);
int			ft_check_action(char *str);
void		ft_sort(char *line, f_arg **list_a, f_arg **list_b, int instruction);
void		ft_s(char *line, f_arg **list_a, f_arg **list_b, int instruction);
void		ft_p(char *line, f_arg **list_a, f_arg **list_b, int instruction);
void		ft_r(char *line, f_arg **list_a, f_arg **list_b, int instruction);
void		ft_rr(char *line, f_arg **list_a, f_arg **list_b, int instruction);

#endif
