NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS =  src/so_long.c \
			src/draw_map.c \
			src/check_map.c \
			src/exit_prog.c \
			src/flood_fill.c \
			src/moving.c \
			src/image.c \
			src/copy_grid.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			libft/ft_split.c \
			libft/ft_strdup.c \
			libft/ft_strlen.c \
			printf/ft_printf.c \
			printf/ft_printf_utils.c \
			

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
