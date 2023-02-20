NAME = push_swap
NAME_B = checker

SRC_1 = push_swap.c

SRC_2 = include/push_swap/move/push.c include/push_swap/move/reverse.c \
		include/push_swap/move/rotate.c include/push_swap/move/swap.c \
		include/push_swap/input_check/ft_check_input.c \
		include/push_swap/input_check/ft_check_sort.c\
		include/push_swap/sorting/ft_sorting.c \
		include/push_swap/sorting/ft_count_move_to_b.c\
		include/push_swap/sorting/ft_check_maxmin.c\
		include/push_swap/sorting/ft_pushing_to_b.c\
		include/push_swap/sorting/ft_sorting_a.c \
		include/push_swap/sorting/ft_check_to_b.c \
		include/push_swap/sorting/ft_check_pusha.c\
		include/push_swap/close_error/ft_close.c\
		include/push_swap/close_error/ft_error.c\

BONUS = include/bonus/checker.c \
		libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c \

OBJ_1 = $(SRC_1.c=.o)
OBJ_1 = $(SRC_2.c=.o)

BOBJ = $(BONUS.c=.o)

CC = gcc
FLAG = -Wall -Werror -Wextra

FTPRINTF = libs/ft_printf/
LIBFT := libs/libft/
LIBRARY := libs/libft/libft.a libs/ft_printf/libftprintf.a

all :
		make -C $(FTPRINTF)
		make -C $(LIBFT)
	$(CC) $(FLAGS) $(SRC_1) $(SRC_2) $(LIBRARY) -o $(NAME)

bonus : all
	$(CC) $(FLAGS) $(BONUS) $(SRC_2) $(LIBRARY) -o $(NAME_B)

clean: 
		make clean -C $(LIBFT)
		make clean -C $(FTPRINTF)
	rm -f $(OBJ_1)
	rm -f $(OBJ_2)
	rm -f $(BOBJ)

fclean: clean
		make fclean -C $(LIBFT)
		make fclean -C $(FTPRINTF)
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all clean