# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zabderra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 19:52:43 by zabderra          #+#    #+#              #
#    Updated: 2022/06/03 19:52:45 by zabderra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGC = -Wall -Wextra -Werror
CC = gcc
c_src = minitalk_utils.c
c_obj=$(c_src:.c=.o)
server = server 
client = client
all: $(server) $(client)


$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server)
$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj)
fclean: clean
	rm -rf $(client) $(server)
re: fclean all
