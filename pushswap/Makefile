# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 12:56:00 by jebossue          #+#    #+#              #
#    Updated: 2017/10/20 19:59:13 by jebossue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCDIR	= srcs
INCDIR	= includes

SRCNAM	= ft_checker.c ft_ini.c ft_sort.c ft_checkpile.c ft_visual.c\
		ft_instruction.c ft_rotate.c ft_free.c

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
OBJ		= $(SRC:%.c=%.o)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)
LDFLAGS	= -L $(LIBFTDIR) -lft

LIBFTNAM	= libft.a
LIBFTDIR	= ../libft/
LIBFT		= $(LIBFTNAM:%=$(LIBFTDIR)/%)

INCNAM = ft_push_swap.h
INC = $(INCNAM:%=$(INCDIR)/%)

GIT	= README.md

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(INC)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re $(LIBFT)

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
