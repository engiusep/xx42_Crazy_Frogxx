# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 15:47:59 by engiusep          #+#    #+#              #
#    Updated: 2025/03/31 14:49:46 by engiusep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb3 -MMD -MP

SRCS = philo.c \
       libft/ft_atoi.c

MAKEDIR = make
OBJDIR = make/objs
DEPDIR = make/deps

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:%.c=$(DEPDIR)/%.d)

HEADER = philo.h

COMPILED = 0
MESSAGE_COLOR_GREEN = \033[1;32m
MESSAGE_COLOR_BLUE = \033[1;34m
MESSAGE_COLOR_YELLOW = \033[1;33m
MESSAGE_COLOR_RED = \033[1;31m
MESSAGE_RESET = \033[1;0m

all: $(NAME)
	@if [ $(COMPILED) -eq 1 ]; then \
		echo "$(MESSAGE_COLOR_BLUE)compilation done 🎉$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_BLUE)everything is already up to date 😉$(MESSAGE_RESET)"; \
	fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@$(eval COMPILED := 1)

$(OBJDIR)/%.o: %.c
	@echo "$(MESSAGE_COLOR_YELLOW)Compiling $<... 🛠️$(MESSAGE_RESET)"
	@mkdir -p $(dir $@) $(dir $(DEPDIR)/$*)
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@
	@mv -f $(basename $@).d $(DEPDIR)/$(notdir $(basename $@)).d
	@$(eval COMPILED := 1)
	@echo "$(MESSAGE_COLOR_GREEN)Compilation of $< done! ✅$(MESSAGE_RESET)"

-include $(DEPS)

clean:
	@if [ -d $(MAKEDIR) ]; then \
		rm -rf $(MAKEDIR); \
		echo "$(MESSAGE_COLOR_RED)all object files deleted 🗑️$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_GREEN)nothing to clean 😉$(MESSAGE_RESET)"; \
	fi

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
