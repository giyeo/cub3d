BIN			= a.out

# UNITY
UNITY_DIR 	= Unity
UNITY_INC 	= unity.h
UNITY_SRC 	= unity.c
UNITY_SRCS	= $(addprefix $(UNITY_DIR)/, $(UNITY_SRC))

# SRC TESTS
TST_SRC_DIR	=	test_srcs
TST_SRCS	=	$(TST_SRC_DIR)/*/**.c \
				$(TST_SRC_DIR)/**.c

# MODULO A SER TESTADO
MAIN_PJ		=	../prod
SRC_DIR		=	$(addprefix $(MAIN_PJ)/, srcs)
SRC_MODULE	=	$(SRC_DIR)/parser/*.c \
				$(SRC_DIR)/utils/*.c \
				$(SRC_DIR)/free/*.c \
				../prod/libft/srcs/ft_mtxcpy.c \
				../prod/libft/srcs/ft_destroy_matrix.c

# MODULO PARA ANJOSE (O VÁLIDO PARA O PROJETO PRINCIPAL É O DE CIMA)
# SRC_DIR		=	./srcs
# SRC_MODULE	=	$(SRC_DIR)/*.c


SRCS		=	$(TST_SRCS) \
				$(SRC_MODULE)

LIBFT_LINK	=	-L$(MAIN_PJ)/libft -lft

INCLUDE		=	-I $(UNITY_DIR)/ \
				-I $(MAIN_PJ)/includes \
				-I $(MAIN_PJ)/libft/includes \
				-I $(MAIN_PJ)/minilibx \
				-I test_srcs/

all:
	@make -C $(MAIN_PJ)/libft
	gcc -g $(INCLUDE) $(SRCS) $(UNITY_SRCS) $(LIBFT_LINK) -o $(BIN)
	./$(BIN)

clean:
	@make fclean -C $(MAIN_PJ)/libft
	rm -rf ./$(BIN)

debug:
	gcc -g $(INCLUDE) $(SRCS) $(UNITY_SRCS) $(LIBFT_LINK) -o $(BIN)
	gdb --tui ./$(BIN)

valgrind:
	gcc -g $(INCLUDE) $(SRCS) $(UNITY_SRCS) $(LIBFT_LINK) -o $(BIN)
	valgrind --leak-check=full ./$(BIN)

.PHONY: all clean debug valgrind

