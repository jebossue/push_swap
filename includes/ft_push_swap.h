/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:32:44 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/16 21:42:11 by jebossue         ###   ########.fr       */
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
	struct c_arg	*begin_a;
	struct c_arg	*end_a;
	struct c_arg	*begin_b;
	struct c_arg	*end_b;
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
void		ft_free_pile_a(d_arg *param, f_arg *list);
void		ft_free_pile_b(d_arg *param, f_arg *list);
int			ft_check_action(char *str);
void		ft_sort(d_arg **pile_a, d_arg **pile_b, int instruction,
		f_arg **list);
void		ft_s(d_arg **pile_a, d_arg **pile_b, int instruction,
		f_arg **list);
void		ft_pa(d_arg **pile_a, d_arg **pile_b, f_arg **list);
void		ft_pb(d_arg **pile_a, d_arg **pile_b, f_arg **list);
void		ft_r(f_arg **list_a, f_arg **list_b, int instruction);
void		ft_rr(f_arg **list_a, f_arg **list_b, int instruction);
int			ft_checkpile_s(d_arg *list);
int			ft_checkpile_p(d_arg *list);
void		ft_adjustpile_b(d_arg **pile_b, f_arg **list, d_arg *tmp_b_next);
void		ft_adjustpile_a(d_arg **pile_a, f_arg **list, d_arg **tmp_a_next);
void		ft_visual(d_arg *pile_a, d_arg *pile_b, f_arg *list);

#endif
