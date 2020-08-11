# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sronni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 16:13:34 by sronni            #+#    #+#              #
#    Updated: 2020/02/25 16:19:21 by sronni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

INCLUDES = ./include/

SOURCE = ./source/*.c


all:
	gcc -Wall -Werror -Wextra $(SOURCE)  -I$(INCLUDES) -o $(NAME)

clean:
	/BIN/rm -f *.o

fclean: clean
	/BIN/rm -f $(NAME)

re: fclean all
	
