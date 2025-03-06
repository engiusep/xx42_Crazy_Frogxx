NAME_SERVER = server
NAME_CLIENT	= client

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c 
SRCS_CLIENT = client.c 
SRCS_UTILS = utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(OBJS_UTILS)

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(OBJS_UTILS)

all: $(NAME_SERVER) $(NAME_CLIENT)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_UTILS)
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(OBJS_UTILS)

re: fclean all

.PHONY: all clean fclean re