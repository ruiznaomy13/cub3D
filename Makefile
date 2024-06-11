# ************************************************************************ #
#    #
#      ███╗   ███╗ █████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗      #
#      ████╗ ████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝      #
#      ██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░      #
#      ██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░      #
#      ██║ ╚═╝ ██║██║  ██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗      #
#      ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝      #
#    #
# ************************************************************************ #

NAME		= cub3D
HEADER		= lib/cub3D.h

INCLUDE		= -I lib/ -I inc/libft -I inc/ft_printf -I inc/mlx

CC			= gcc
C_FLAGS		= -Wall -Werror -Wextra -O3 -g -fPIE
LIBMLX		= inc/mlx42
#MLX_FLAGS	= -L inc/mlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR		= ./src
OBJ_DIR		= ./obj

SILENCE =  --no-print-directory

SRCS		= main.c checker.c checkerAux.c auxiliarFunctions.c \
			utils.c mapStruct.c utils_2.c ray.c print.c ft_free_game.c \
			moves.c ray_aux.c textures.c

OBJ			= $(addprefix ${OBJ_DIR}/,  ${SRCS:.c=.o})
DEPS		= $(addprefix ${OBJ_DIR}/,  ${SRCS:.c=.d})
RUTAS		= inc/libft/libft.a inc/ft_printf/libftprintf.a $(LIBMLX)/build/libmlx42.a -ldl \
			-L/opt/hombrew/Cellar/glfw/3.4 -lglfw -lm

######## COLORS #########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m

all: sub_make $(NAME)	

all: sub_make $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) -MT $@ $(C_FLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

sub_make:
	@$(MAKE) -sC inc/libft CFLAGS="$(CFLAGS) -fPIE" $(SILENCE)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
#	@$(MAKE) -sC inc/mlx $(SILENCE)
	@$(MAKE) -sC inc/ft_printf $(SILENCE)

$(NAME): $(OBJ)
	@$(CC) $(C_FLAGS) $(OBJ) $(RUTAS) -o $@
	@echo "$(GREEN)  \n    🐉🧚  cub3D compiled  🐉🧚\n$(NC)"

-include $(DEPS)

clean:
	@$(MAKE) clean -sC inc/libft $(SILENCE)
	@rm -rf $(LIBMLX)/build
#	@$(MAKE) clean -sC inc/mlx $(SILENCE)
	@$(MAKE) clean -sC inc/ft_printf $(SILENCE)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED) \nDestruction successful\n$(NC)"

fclean: clean
	@$(MAKE) fclean -sC inc/libft $(SILENCE)
	@$(MAKE) fclean -sC inc/ft_printf $(SILENCE)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all sub_make clean fclean re 
