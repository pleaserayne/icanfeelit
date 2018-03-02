# ************************************************************************** #
#                                                                            #
#              ''''''''      ''''  ''''        ''''''''     ''''''''         #
#           :.:.:.:.:     .:.:      :.:.      :.:.:.:.:    .:.:.:.:.         #
#          :::         ::::          ::::    :::    ::::  ::                 #
#         +:+       :+:+              :+:+  :+:     :+:  :+:+:+:+:           #
#        #+#       +#+#              +#+#  +#+     +#+  +#+#+#+#+            #
#       +#+         #+#+          #+#+    #+#    +#+#  #+                    #
#      #########     ####      ####      #########    #########              #
#       ########      ####  ####        ########     ######## .berlin        #
#      ______________________________________________________________        #
#      ____________UNIVERSITY OF APPLIED SCIENCES BERLIN_____________        #
#                                                                            #
#      "Makefile"           by:  boris  <boris.sabelfeld@code.berlin>        #
#                                                                            #
# ************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS = srcs/checkfill.c srcs/parsefill.c srcs/miscfill.c srcs/solvefill.c srcs/main.c

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -o $(NAME) -I includes $(SRCS)

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
