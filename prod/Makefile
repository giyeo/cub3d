
# MAIN VARIABLES
NAME		:= cub3d
CC			:= cc
CFLAGS		:= #-Wall -Wextra -Werror

# FLAG := -lm -lbsd -lXext -lX11 \
# 	-fsanitize=address

# LIBRARIES
## libft
LIBFT		:= ft
LIBFT_DIR	:= ./libft
INCS_LFT	:= libft.h
LIBFT_LINK	:= -L$(LIBFT_DIR) -l$(LIBFT)

## minilibx


# INCLUDES
INCS_DIR	:= ./includes
INCS		:= cub3d.h
MAIN_HEADER := $(addprefix $(INCS_DIR)/, $(INCS))

INC_FLAGS	:= -I $(INCS_DIR) -I $(LIBFT_DIR)/includes

# SOURCES
SRCS_DIR	:= srcs
SRCS 		:= main.c

SRCS_PTH	:= $(addprefix $(SRCS_DIR)/, $(SRCS))

# OBJECTS
OBJS_DIR	:= ./objs
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# EXPLICIT COMPILATION OF THE OBJECTS
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(MAIN_HEADER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# TARGETS
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(INC_FLAGS) $(LIBFT_LINK) -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	@make $@ -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

# # minilibx_clean:
# # 	make clean

.PHONY: clean fclean re all