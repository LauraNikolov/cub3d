# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  PROJECT  ----------------------------------------------------- #
NAME			=	cub3d

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR			=	srcs/
INC_DIR			= 	includes/
OBJ_DIR			=	objs/
LFT_DIR			=	libft/
MLX_DIR			=	mlx_linux/
EXEC_DIR		=	exec/
PARSE_DIR		=	parsing/
#UTILS_DIR		=	utils/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	libft/libft.a

MLX				=	mlx_linux/libmlx_Linux.a

SRC_FLS			=	main.c \
					$(EXEC_DIR)init_game.c \
					$(EXEC_DIR)raycaster.c \
					$(EXEC_DIR)utils.c \
					$(EXEC_DIR)render.c \
					$(EXEC_DIR)handle_moves.c \
					$(EXEC_DIR)utils_move.c \
					$(EXEC_DIR)textures.c \
					$(PARSE_DIR)init_utils.c \
					$(PARSE_DIR)init.c \
					$(PARSE_DIR)malloc_utils.c \
					$(PARSE_DIR)maps.c \
					$(PARSE_DIR)parse_texture.c \
					$(PARSE_DIR)realloc_tab.c \
					$(PARSE_DIR)rgb.c \
					$(PARSE_DIR)string_utils.c \
					$(PARSE_DIR)gnl/gnl_utils.c \
					$(PARSE_DIR)gnl/gnl.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# ------------  FLAGS  -------------------------------------------------------- #
CFLAGS			=	-Wall -Wextra -Werror -g
LFLAGS			=	-L./$(LFT_DIR) -lft
LIB_FLAGS		=	-lreadline -lncurses -lm
MLX_FLAGS		=	-Lmlx_linux -lmlx_Linux -L/usr/lib $(I_MLX) -lXext -lX11 -lm -lz

MAKE_FLAGS		=	-s -C
RM_FLAGS		=	-rf

I_SRC			= 	-I $(INC_DIR)
I_MLX			=	-I $(MLX_DIR)
INCLUDES		=	$(I_SRC) -I/usr/include $(I_MLX)

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MFC				=	make fclean
MC				=	make clean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJ_DIR) $(OBJS) $(LFT) $(MLX)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS) $(LIB_FLAGS) $(MLX_FLAGS) -Lmlx_linux -lmlx_Linux
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(EXEC_DIR)
					@mkdir -p $(OBJ_DIR)$(PARSE_DIR)
					@mkdir -p $(OBJ_DIR)$(PARSE_DIR)/gnl

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

$(MLX):
					@$(MK) $(MAKE_FLAGS) $(MLX_DIR)

clean:
					@$(RM) $(OBJ_DIR)
					@echo "$(YELLOW)Cleaned $(OBJ_DIR)$(DEFAULT)"
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)
					@echo "$(YELLOW)Cleaned $(LFT_DIR)$(DEFAULT)"
					@$(MC) $(MAKE_FLAGS) $(MLX_DIR)
					@echo "$(YELLOW)Cleaned $(MLX_DIR)$(DEFAULT)"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(RED)Cleaned $(NAME)$(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re