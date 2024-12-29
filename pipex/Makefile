# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 19:12:38 by engiusep          #+#    #+#              #
#    Updated: 2024/12/29 19:20:23 by engiusep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = 
RM = rm -f

SRCS =  pipex.c \
			utils.c

HEADER = pipex.h

LIBFT = ../libft
LIBFT_HEADER = ../libft/libft.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT) -lft -c $@ -o $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
