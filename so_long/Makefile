NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =  so_long.c \
			draw_map.c \
			free.c \
			check_map.c \
			exit_prog.c \
			flood_fill.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			libft/ft_split.c \
			libft/ft_strdup.c \
			libft/ft_strlen.c

HEADER = so_long.h

OBJS = $(SRCS:.c=.o)
MLX= minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -lX11 -lXext -lm
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
