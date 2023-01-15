# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 00:00:12 by anjose-d          #+#    #+#              #
#    Updated: 2023/01/15 19:08:19 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAIN VARIABLES
NAME		:=	cub3D
NAME_BNS	:=	cub3D_bonus
CC			:=	cc
CFLAGS		:=  -O3 -Wall -Wextra -Werror

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
INCS_BNS	:=	cub3d_bonus.h
MAIN_HEADER	:=	$(addprefix $(INCS_DIR)/, $(INCS))
MAIN_HDR_BNS:=	$(addprefix $(INCS_DIR)/, $(INCS_BNS))
TRACK_INC	:=	$(INCS_DIR)/defines.h $(INCS_DIR)/errors.h
TRACK_INCBNS:=	$(INCS_DIR)/defines_bonus.h $(INCS_DIR)/errors_bonus.h

INC_FLAGS	:=	-I $(INCS_DIR) -I $(LIBFT_DIR)/includes \
				-I $(MLX_DIR)
LINK_FLAGS	:=	-lm $(LIBFT_LINK) $(MLX_LINK)

# SOURCES
PARSER_DIR	:=	parser
PARSER_SRCS	:=	extension_check.c \
				file_check.c \
				line_count.c \
				read_file.c \
				parser_and_validate.c \
				file_validate.c \
				find_map_start.c \
				validate_config.c \
				validate_config_utils1.c \
				validate_config_utils2.c \
				validate_map.c

HOOKS_DIR	:=	hooks
HOOKS_SRCS	:=	end_game.c \
				key_mapping.c \
				load_game.c

RENDER_DIR	:=	render
RENDER_SRCS	:=	img_pix_put.c \
				render_line.c

UTILS_DIR	:=	utils
UTILS_SRCS	:=	utils.c \
				only_these.c \
				config_init.c \
				find_player.c \
				error_handler.c \
				load_textures.c \
				config_populate.c \
				count_occur.c skip_space.c \

FREE_DIR	:=	free
FREE_SRCS	:=	free_config.c

EXECUTION_DIR	:= 	execution
EXECUTION_SRCS	:=  raycasting.c \
					update.c

SRCS_DIR	:=	srcs
SRCS		:=	main.c \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS)) \
				$(addprefix $(FREE_DIR)/, $(FREE_SRCS)) \
				$(addprefix $(HOOKS_DIR)/, $(HOOKS_SRCS)) \
				$(addprefix $(RENDER_DIR)/, $(RENDER_SRCS)) \
				$(addprefix $(EXECUTION_DIR)/, $(EXECUTION_SRCS))

SRCS_PTH	:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# SOURCES BONUS
PARSER_DIR	:=	parser
PARSER_SRCS	:=	extension_check_bonus.c \
				file_check_bonus.c \
				line_count_bonus.c \
				read_file_bonus.c \
				parser_and_validate_bonus.c \
				file_validate_bonus.c \
				find_map_start_bonus.c \
				validate_config_bonus.c \
				validate_config_utils1_bonus.c \
				validate_config_utils2_bonus.c \
				validate_map_bonus.c

HOOKS_DIR	:=	hooks
HOOKS_SRCS	:=	end_game_bonus.c \
				key_mapping_bonus.c \
				load_game_bonus.c

RENDER_DIR	:=	render
RENDER_SRCS	:=	img_pix_put_bonus.c \
				render_line_bonus.c \
				render_line_minimap_bonus.c


UTILS_DIR	:=	utils
UTILS_SRCS	:=	utils_bonus.c \
				only_these_bonus.c \
				config_init_bonus.c \
				find_player_bonus.c \
				error_handler_bonus.c \
				load_textures_bonus.c \
				config_populate_bonus.c \
				count_occur_bonus.c skip_space_bonus.c \

FREE_DIR	:=	free
FREE_SRCS	:=	free_config_bonus.c

EXECUTION_DIR	:= 	execution
EXECUTION_SRCS	:=  raycasting_bonus.c \
					update_bonus.c \
					minimap_bonus.c

SRCS_DIR_BNS:=	srcs_bonus
SRCS_BNS	:=	main_bonus.c \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS)) \
				$(addprefix $(FREE_DIR)/, $(FREE_SRCS)) \
				$(addprefix $(HOOKS_DIR)/, $(HOOKS_SRCS)) \
				$(addprefix $(RENDER_DIR)/, $(RENDER_SRCS)) \
				$(addprefix $(EXECUTION_DIR)/, $(EXECUTION_SRCS))

SRCS_PTH_BNS:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# OBJECTS
OBJS_DIR	:=	./objs
OBJS		:=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# BONUS OBJECTS
OBJS_DIR_BNS:=	./objs_bns
OBJS_BNS	:=	$(addprefix $(OBJS_DIR_BNS)/, $(SRCS_BNS:.c=.o))

# EXPLICIT COMPILATION OF THE OBJECTS
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(MAIN_HEADER) $(TRACK_INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJS_DIR_BNS)/%.o: $(SRCS_DIR_BNS)/%.c $(MAIN_HDR_BNS) $(TRACK_INCBNS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@
	
# TARGETS
all: $(NAME)

bonus: $(NAME_BNS)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(INC_FLAGS) $(LINK_FLAGS) -o $@

$(NAME_BNS): $(OBJS_BNS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS_BNS) $(CFLAGS) $(INC_FLAGS) $(LINK_FLAGS) -o $@

clean:
	rm -rf $(OBJS_DIR) $(OBJS_DIR_BNS)

fclean: clean minilibx_clean
	@make $@ -C $(LIBFT_DIR)
	rm -rf $(NAME) $(NAME_BNS)

run: all
	./$(NAME) maps/simple/corridor.cub

run_bonus: bonus
	./$(NAME_BNS) maps/simple/mine.cub

re: fclean all

minilibx_clean:
	@make clean -C $(MLX_DIR)

.PHONY: clean fclean re all minilibx_clean
