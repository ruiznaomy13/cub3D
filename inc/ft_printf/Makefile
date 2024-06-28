NAME	= libftprintf.a

HEADER	= ft_printf.h

INCLUDE = -I./

SRCS	= ft_printf.c ft_funlibft.c ft_funxp.c

OBJS	= ${SRCS:.c=.o}

DEPS	= $(addsuffix .d, $(basename ${OBJS}))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -fPIE

# COLORS
GREEN = \033[1;92m
NC = \033[0m

%.o: %.c Makefile
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	@ar src ${NAME} ${OBJS}
	@echo "$(GREEN)FT_PRINTF compiled$(NC)"

-include	${DEPS}

clean: 
			@rm -rf ${OBJS} ${DEPS}
			
fclean:		clean
			@rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
