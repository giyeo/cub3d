NAME := cube3d

SRC :=	main.c libft_utils.c get_input.c utils.c \
		parse.c parse_utils.c ../prod/libft/libft.a

OBJS := $(SRC:.c=.o)

FLAG := -lm -lbsd -lXext -lX11 \
	-fsanitize=address

CFLAG := -Wall -Wextra -Werror

all: $(NAME)

bonus: all

# $(NAME): $(OBJS) $(SRC)
# 	make --no-print-directory -C ../minilibx-linux
# 	gcc $(OBJS) -o $(NAME) $(CFLAG) ../minilibx-linux/libmlx_Linux.a $(FLAG)

$(NAME): $(OBJS) $(SRC)
	gcc $(OBJS) -o $(NAME) $(CFLAG) $(FLAG)
%.o: %.c
	gcc $(CFLAG) -c $< -o $@

.PHONY: clean fclean re all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

minilibx_clean:
	make clean

re: fclean all