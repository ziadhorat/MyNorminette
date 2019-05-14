# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 06:56:37 by zmahomed          #+#    #+#              #
#    Updated: 2019/04/15 03:08:26 by zmahomed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = norminette

SRC = ./srcs/*.c

SRCO = *.o

INCLUDE = ./includes/*.h

all: $(NAME) clean

$(NAME):
	gcc -c $(SRC)
	gcc $(SRCO) -o $(NAME) 

clean:
	/bin/rm -f *.o

fclean: clean 
	/bin/rm -f $(NAME)

re: fclean all
