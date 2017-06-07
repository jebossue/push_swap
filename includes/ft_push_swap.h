/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:32:44 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/07 17:00:38 by jebossue         ###   ########.fr       */
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

int			ft_isint(char **av);
int			ft_isdoublon(char **av);
int			get_next_line(const int fd, char **line);

#endif
