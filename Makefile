NAME = ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = 'Common Core'/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include and Linking flags
INCLUDES = -I$(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
