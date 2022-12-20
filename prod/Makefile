
# MAIN VARIABLES
NAME		:=	cub3d
CC			:=	cc
CFLAGS		:=	-O3 -Wall -Wextra -Werror

# LIBRARIES
## libft
LIBFT		:=	ft
LIBFT_DIR	:=	./libft
INCS_LFT	:=	libft.h
LIBFT_LINK	:=	-L$(LIBFT_DIR) -l$(LIBFT)

## minilibx
### minilibx requirements
#### sudo apt-get install gcc make xorg libxext-dev libbsd-dev
MLX			:=	mlx
MLX_DIR		:=	./minilibx
MLX_LINK	:=	-L$(MLX_DIR) -l$(MLX) -lXext -lX11

# INCLUDES
INCS_DIR	:=	./includes
INCS		:=	cub3d.h
MAIN_HEADER	:=	$(addprefix $(INCS_DIR)/, $(INCS))

INC_FLAGS	:=	-I $(INCS_DIR) -I $(LIBFT_DIR)/includes \
				-I $(MLX_DIR)
LINK_FLAGS	:=	-lm $(LIBFT_LINK) $(MLX_LINK) -fsanitize=address

# SOURCES
PARSER_DIR	:=	parser
PARSER_SRCS	:=	extension_check.c \
				file_check.c \
				line_count.c \
				read_file.c \
				parser_and_validate.c \
				file_validate.c \
				validate_config.c \
				find_split_line.c \
				#validate_map.c

UTILS_DIR	:=	utils
UTILS_SRCS	:=	utils.c \
				only_these.c \
				config_init.c \
				find_player.c

FREE_DIR	:=	free
FREE_SRCS	:=	free_config.c

SRCS_DIR	:=	srcs
SRCS		:=	main.c \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS)) \
				$(addprefix $(FREE_DIR)/, $(FREE_SRCS))

SRCS_PTH	:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# OBJECTS
OBJS_DIR	:=	./objs
OBJS		:=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# EXPLICIT COMPILATION OF THE OBJECTS
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(MAIN_HEADER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# TARGETS
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(INC_FLAGS) $(LINK_FLAGS) -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean minilibx_clean
	@make $@ -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

minilibx_clean:
	@make clean -C $(MLX_DIR)

.PHONY: clean fclean re all minilibx_clean