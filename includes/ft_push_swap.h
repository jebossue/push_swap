/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:32:44 by jebossue          #+#    #+#             */
/*   Updated: 2017/09/25 17:11:15 by jebossue         ###   ########.fr       */
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
void		ft_free_pile(d_arg *param, f_arg *list);
int			ft_check_action(char *str);
void		ft_sort(f_arg **list_a, f_arg **list_b, int instruction);
void		ft_s(f_arg **list_a, f_arg **list_b, int instruction);
void		ft_pa(f_arg **list_a, f_arg **list_b);
void		ft_pb(f_arg **list_a, f_arg **list_b);
void		ft_r(f_arg **list_a, f_arg **list_b, int instruction);
void		ft_rr(f_arg **list_a, f_arg **list_b, int instruction);
int			ft_checkpile_s(f_arg *list);
int			ft_checkpile_p(f_arg *list);
void		ft_adjustpile(f_arg **list);

#endif
