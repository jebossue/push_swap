# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 12:56:00 by jebossue          #+#    #+#              #
#    Updated: 2017/10/22 18:01:19 by jebossue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GIT	= README.md

all:
	$(MAKE) -C ./libft/
	$(MAKE) -C ./checker/
	$(MAKE) -C ./pushswap/

.PHONY: all

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)

check: no

clean:
	$(MAKE) -C ./libft/ clean
	$(MAKE) -C ./checker/ clean
	$(MAKE) -C ./pushswap/ clean

fclean:
	$(MAKE) -C ./libft/ fclean
	$(MAKE) -C ./checker/ fclean
	$(MAKE) -C ./pushswap/ fclean

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
