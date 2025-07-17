# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 15:47:59 by engiusep          #+#    #+#              #
#    Updated: 2025/07/17 16:19:38 by engiusep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3
SRC_FILES = main_philo.c \
			free_all.c \
			routine_monitor.c \
			routine.c \
			utils.c \

RM = rm -f
OBJ_DIR = .objs
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
INCLUDE_DIR = ./include
INCLUDES = -I$(INCLUDE_DIR)
HEADER = $(addprefix $(INCLUDE_DIR)/, philo.h)

all: $(NAME)
	@echo "$(NAME) ready to run!"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Created $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiled $< to $@"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	@echo $(OBJS)
	@echo $(OBJ_DIR)/main_philo.o

.PHONY: all clean fclean re