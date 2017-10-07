# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 12:56:00 by jebossue          #+#    #+#              #
#    Updated: 2017/06/23 18:55:01 by jebossue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker

SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes

SRCNAM	= ft_checker.c ft_ini.c ft_sort.c ft_checkpile.c ft_visual.c

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)
LDFLAGS	= -L $(LIBFTDIR) -lft

LIBFTNAM	= libft.a
LIBFTDIR	= ./libft/
LIBFT		= $(LIBFTNAM:%=$(LIBFTDIR)/%)

INCNAM = ft_push_swap.h
INC = $(INCNAM:%=$(INCDIR)/%)

GIT	= README.md

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC) $(LIBFT)
	mkdir -p $(OBJDIR)
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
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
