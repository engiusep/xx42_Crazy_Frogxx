# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 16:13:47 by engiusep          #+#    #+#              #
#    Updated: 2024/11/25 16:52:13 by engiusep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

FILES = ft_printf.c \
		ft_printf_utils.c \

OBJS = $(FILES:.c=.o)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re