# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:48:53 by aoustani          #+#    #+#              #
#    Updated: 2022/03/19 12:09:18 by aoustani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	 minitalk.h

SRC		=	function_utils.c 

O_SRC	=	function_utils.o


M_SRC	=	client.c\

M_OBJ	= 	$(M_SRC:.c=.o)

M_SRC2	= 	server.c \

M_OBJ2	= 	$(M_SRC2:.c=.o)


B_SRC	=		client_bonus.c\

B_OBJ	= 	$(B_SRC:.c=.o)

B_SRC2	= 	server_bonus.c \

B_OBJ2	= 	$(B_SRC2:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

all: server client
	$(CC) $(FLAGS) $(M_OBJ2) $(O_SRC) -o server
	$(CC) $(FLAGS) $(M_OBJ) $(O_SRC) -o client

bonus: $(B_OBJ) $(B_OBJ2) $(O_SRC)
	$(CC) $(FLAGS) $(B_OBJ2) $(O_SRC)  -o server_bonus
	$(CC) $(FLAGS) $(B_OBJ)  $(O_SRC) -o client_bonus

client: $(M_SRC) $(O_SRC)
	$(CC) $(FLAGS) $(M_SRC) -c

server:$(M_SRC2) $(O_SRC)
	$(CC) $(FLAGS) $(M_SRC2) -c
 
$(O_SRC) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -c

$(M_OBJ):$(M_SRC)
	$(CC) $(FLAGS) $(M_SRC) -c

$(M_OBJ2):$(M_SRC2)
	$(CC) $(FLAGS) $(M_SRC2) -c

$(B_OBJ):$(B_SRC)
	$(CC) $(FLAGS) $(B_SRC) -c

$(B_OBJ2):$(B_SRC2)
	$(CC) $(FLAGS) $(B_SRC2) -c

clean:
	rm -f *.o

fclean:clean
	rm -f client server

re : fclean all