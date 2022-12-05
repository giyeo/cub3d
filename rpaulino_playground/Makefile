NAME := cub3d

SRC :=	main.c

OBJS := $(SRC:.c=.o)

FLAG := -lm -lbsd -lXext -lX11 \
	-fsanitize=address

CFLAG := #-Wall -Wextra -Werror

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(SRC)
	make --no-print-directory -C ../prod/minilibx
	gcc $(OBJS) -o $(NAME) $(CFLAG) ../prod/minilibx/libmlx_Linux.a $(FLAG) -O3

# $(NAME): $(OBJS) $(SRC)
# 	gcc $(OBJS) -o $(NAME) $(CFLAG) $(FLAG)

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