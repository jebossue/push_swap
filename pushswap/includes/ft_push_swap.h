/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:32:44 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/28 20:47:40 by jebossue         ###   ########.fr       */
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
	int				flag;
	struct c_arg	*next;
	struct c_arg	*prev;
}				d_arg;

typedef struct	e_arg
{
	struct c_arg	*begin_a;
	struct c_arg	*end_a;
	struct c_arg	*begin_b;
	struct c_arg	*end_b;
	int				size_a;
	int				size_b;
	int				pivot;
	int				*array;
	int				size_pivot;
	int				pivotb;
	int				size_pivotb;
	int				elementsinb;
	int				option;
	int				position_r;
	int				position_rr;
	int				pivot_bloc;
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
void		ft_free_pile_a(d_arg **param, f_arg **list);
void		ft_free_pile_b(d_arg **param, f_arg **list);
int			ft_check_action(char *str);
void		ft_sort(d_arg **pile_a, d_arg **pile_b, int instruction,
		f_arg **list);
void		ft_s(d_arg **pile_a, d_arg **pile_b, int instruction,
		f_arg **list);
void		ft_pa(d_arg **pile_a, d_arg **pile_b, f_arg **list);
void		ft_pb(d_arg **pile_a, d_arg **pile_b, f_arg **list);
void		ft_r(d_arg **pile_a, d_arg **pile_b, f_arg **list,
		int instruction);
void		ft_rr(d_arg **pile_a, d_arg **pile_b, f_arg **list,
		int instruction);
int			ft_checkpile_s(d_arg *list);
int			ft_checkpile_p(d_arg *list);
void		ft_adjustpile_b(d_arg **pile_b, f_arg **list, d_arg *tmp_b_next);
void		ft_adjustpile_a(d_arg **pile_a, f_arg **list, d_arg **tmp_a_next);
void		ft_visual(d_arg *pile_a, d_arg *pile_b, f_arg *list);
int			ft_putelements(d_arg **pile_a, f_arg **list, h_arg arg);
void		ft_doublelst(char *av, d_arg **pile_a, f_arg **list);
void		ft_instruction(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_free_full_av(char **full_av);
void		ft_free_all(d_arg **pile_a, d_arg **pile_b, f_arg **list);
int			ft_isok(f_arg *lst);
void		ft_algo(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_basicsort(int *array, f_arg **list);
int			ft_issort(f_arg **list, int *array);
void		ft_pivot(f_arg **list);
void		ft_putb(f_arg **list, int pivot, d_arg **pile_a, d_arg **pile_b);
void		ft_pivotb(f_arg **list);
void		ft_fifthelem(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_size(f_arg **list);
void		ft_algothree(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_5elementsinb(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_algotwo(f_arg **list, d_arg **pile_a, d_arg **pile_b);
int			ft_createpilev2(d_arg **pile_a, d_arg **pile_b, f_arg **list);
void		ft_r_or_rr_a(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_r_or_rr_b(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_putflags(f_arg **list);
void		ft_sort_rest(f_arg **list, d_arg **pile_a, d_arg **pile_b,
		int flag_pivot);
void		ft_separateb(f_arg **list, d_arg **pile_a, d_arg **pile_b);
int			ft_isalreadysort(f_arg **list, int flagelem);
void		ft_simplesort(f_arg **list, d_arg **pile_a, d_arg **pile_b);
void		ft_simplethree(f_arg **list, d_arg **pile_a, d_arg **pile_b);

#endif
