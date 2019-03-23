# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 06:56:37 by zmahomed          #+#    #+#              #
#    Updated: 2019/03/23 03:25:46 by zmahomed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MyNorminette

SRC = ./srcs/*.c

SRCO = *.o

FLAG = -Wall -Werror -Wextra

INCLUDE = ./includes/*.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC)
	gcc $(FLAG) $(SRCO) -o $(NAME) 

clean:
	/bin/rm -f *.o

fclean: clean 
	/bin/rm -f $(NAME)

re: fclean all
