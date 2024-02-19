# ************************************************************************ #
#                                                                          #
#      ███╗   ███╗ █████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗      #
#      ████╗ ████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝      #
#      ██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░      #
#      ██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░      #
#      ██║ ╚═╝ ██║██║  ██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗      #
#      ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝      #
#                                                                          #
# ************************************************************************ #

NAME		= cub3D
HEADER		= lib/cub3D.h

INCLUDE		= -I./ -I inc/libft -I inc/ft_printf -I inc/mlx

CC			= gcc
C_FLAGS		= -Wall -Werror -Wextra -03
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(SRC_DIR)/main.c

OBJ			= $(addprefix ${OBJ_DIR}/,$(SRCS:.c=.o))
DEPS		= $(addsuffix .d,$(basename ${OBJS}))
RUTAS		= inc/libft/libft.a inc/minilibx/libmlx.a inc/ft_printf/libftprintf.a

######## COLORS #########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) -MT $@ $(C_FLAGS) -MDD -MP $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) -sC inc/libft
	@$(MAKE) -sC inc/minilibx
	@$(MAKE) -sC inc/ft_printf

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(RUTAS) $(MLX_FLAGS) -o $@
	@echo "$(GREEN)  cub3D compiled $(NC)"

-include $(DEPS)

clean:
	@$(MAKE) clean -sC lib/libft
	@$(MAKE) clean -sC lib/minilibx
	rm -rf $(OBJ_DIR)
	@echo "$(RED) \nDestruction successful\n$(NC)"

fclean: clean
	@$(MAKE) fclean -sC lib/libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re