
# MAIN VARIABLES
NAME		:= cub3d
CC			:= cc
CFLAGS		:= #-Wall -Wextra -Werror

# FLAG := -lm -lbsd -lXext -lX11 \
# 	-fsanitize=address


# INCLUDES


# LIBFT


# MINILIBX


# SOURCES
SRCS_DIR	:= srcs
SRCS 		:= main.c

SRCS_PTH	:= $(addprefix $(SRCS_DIR)/, $(SRCS))

# OBJECTS
OBJS_DIR	:= ./objs
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# %.o: %.c
# 	gcc $(CFLAG) -c $< -o $@
# EXPLICIT COMPILATION OF THE OBJECTS
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# TARGETS
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(FLAG) -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# # minilibx_clean:
# # 	make clean

.PHONY: clean fclean re all