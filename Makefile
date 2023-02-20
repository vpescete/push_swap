NAME = push_swap
NAME_B = checker

SRC_1 = push_swap.c

SRC_2 = move/push.c move/reverse.c move/rotate.c move/swap.c \
		input_check/ft_check_input.c input_check/ft_check_sort.c\
		sorting/ft_sorting.c sorting/ft_count_move_to_b.c sorting/ft_check_maxmin.c\
		sorting/ft_pushing_to_b.c sorting/ft_sorting_a.c sorting/ft_check_to_b.c \
		sorting/ft_check_pusha.c\
		ft_close.c ft_error.c

BONUS = bonus/checker.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ_1 = $(SRC_1.c=.o)
OBJ_1 = $(SRC_2.c=.o)

BOBJ = $(BONUS.c=.o)

CC = gcc
FLAG = -Wall -Werror -Wextra

FTPRINTF = ft_printf/
LIBFT := libft/
LIBRARY := libft/libft.a ft_printf/libftprintf.a

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