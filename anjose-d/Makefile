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
SRC_MODULE	=	$(SRC_DIR)/parser/*.c					# PASTA ../prod/srcs/parser | DEVE TER ALGUM .C lá, se não dá erro

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
	@gcc -g $(INCLUDE) $(SRCS) $(UNITY_SRCS) $(LIBFT_LINK) -o $(BIN)
	./$(BIN)

clean:
	@make fclean -C $(MAIN_PJ)/libft
	rm -rf ./$(BIN)

debug:

valgrind:

.PHONY: all clean debug valgrind

