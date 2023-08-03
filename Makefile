NAME = push_swap

SRC = main.c

MOVE = srcs/move/push.c srcs/move/rotate.c srcs/move/reverse.c srcs/move/swap.c

SRCS = srcs/init.c srcs/init_utils.c srcs/utils_0.c srcs/utils_1.c $(MOVE)

# ANSII COLOR

RED		= \033[0;31m
BLACK	= \033[1;30m
WHITE	= \033[1;37m
BLUE	= \033[1;34m
YELLOW2  = \033[93;226m
GREEN2   = \033[92;118m
GREEN   = \e[92;5;118m
YELLOW  = \e[93;5;226m
GRAY    = \e[33;2;37m
RESET   = \e[0m
CURSIVE = \e[33;3m

OBJS = $(SRCS:.c=.o)
OBJ = $(SRC:.c=.o)

RM = rm -f

FTPRINTF = libs/ft_printf/
LIBFT := libs/libft/
LIBRARY := libs/libft/libft.a libs/ft_printf/libftprintf.a

CC = gcc -Wall -Wextra -Werror -g

.c.o:
	@${CC} -c $< -o ${<:.c=.o} > /dev/null

$(NAME): ${OBJS} $(OBJ)
	@printf "$(CURSIVE)$(YELLOW) 	- Compiling libft ... $(RESET)\n"
	@make -s -C $(LIBFT)
	@printf "\e[0m\e[92m - libft compiled.$(RESET)\n"
	@printf "$(CURSIVE)$(YELLOW) 	- Compiling libft ... $(RESET)\n"
	@make -s -C $(FTPRINTF)
	@printf "\e[0m\e[92m - libft compiled.$(RESET)\n"
	@printf "$(CURSIVE)$(YELLOW) 	- Compiling push_swap ... $(RESET)\n"
	@$(CC) $(OBJS) $(OBJ) $(LIBRARY) -o $(NAME)
	@printf "\e[0m\e[92m - push_swap compiled.$(RESET)\n"

all: $(NAME)

clean:
	@make -s clean -C $(LIBFT)
	@printf "\e[0m\e[92m$(RED) - OBJS libft removed.$(RESET)\n"
	@make -s clean -C $(FTPRINTF)
	@printf "\e[0m\e[92m$(RED) - OBJS ft_printf removed.$(RESET)\n"
	@${RM} $(OBJS)
	@${RM} $(OBJ)
	@printf "\e[0m\e[92m$(RED) - OBJS push_swap removed.$(RESET)\n"

fclean: clean
	@make -s fclean -C $(LIBFT)
	@printf "\e[0m\e[92m$(RED) - library libft removed.$(RESET)\n"
	@make -s fclean -C $(FTPRINTF)
	@printf "\e[0m\e[92m$(RED) - library ft_printf removed.$(RESET)\n"
	@${RM} $(NAME) ${OBJ}
	@${RM} $(NAME) ${OBJS}
	@printf "\e[0m\e[92m$(RED) - push_swap removed.$(RESET)\n"

re: fclean all