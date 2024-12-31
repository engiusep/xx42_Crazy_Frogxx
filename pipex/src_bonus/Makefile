# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 19:12:38 by engiusep          #+#    #+#              #
#    Updated: 2024/12/30 16:39:39 by engiusep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =  pipex_bonus.c \
			utils_bonus.c

HEADER = pipex.h

OBJS = $(SRCS:.c=.o)

LIBFT = ../../libft
LIBFT_HEADER = ../../libft/libft.h


all: $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
