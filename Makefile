NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putstring.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_put_unsigned_nbr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
