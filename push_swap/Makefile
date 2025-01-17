# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 17:10:02 by engiusep          #+#    #+#              #
#    Updated: 2025/01/17 17:22:11 by engiusep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = src/all_cost.c \
			src/check_stack.c \
			src/create_stack.c \
			src/error.c \
			src/push_stack.c \
			src/push_swap.c \
			src/reverse_rotate.c \
			src/rotation.c \
			src/rules.c \
			src/search_index.c \
			src/swap.c
					
OBJS = $(SRCS:.c=.o)

HEADER = include/push_swap.h \
			include/libft.h
LIBFT = include

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

%.o: src/push_swap/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $@ -o $<

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus both clean fclean re