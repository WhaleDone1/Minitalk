# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 13:20:15 by bcarpent          #+#    #+#              #
#    Updated: 2024/05/06 13:20:16 by bcarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj
LIBDIR = Libft
LIBNAME = Libft.a
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_OBJS = $(addprefix $(OBJDIR)/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJDIR)/, $(CLIENT_SRCS:.c=.o))

all: $(OBJDIR) libft server client

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/server.o: $(SRCDIR)/server.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

$(OBJDIR)/client.o: $(SRCDIR)/client.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./$(LIBDIR) -lft

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./$(LIBDIR) -lft

clean:
	rm -rf $(OBJDIR)

libft:
	make -C  $(LIBDIR)

fclean: clean
	rm -f server client
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
