NAME = push_swap

SRC = move/push.c move/reverse.c move/rotate.c move/swap.c \
		check_input/ft_check_input.c check_input/ft_check_sort.c\
		sorting/ft_sorting.c sorting/ft_count_move_to_b.c sorting/ft_check_maxmin.c\
		sorting/ft_pushing_to_b.c sorting/ft_sorting_a.c sorting/ft_check_to_b.c \
		sorting/ft_check_pusha.c\
		push_swap.c ft_close.c ft_error.c

OBJ = $(SRC.c=.o)

CC = gcc
FLAG = -Wall -Werror -Wextra

FTPRINTF = ft_printf/
LIBFT := libft/
LIBRARY := libft/libft.a ft_printf/libftprintf.a

all :
		make -C $(FTPRINTF)
		make -C $(LIBFT)
	$(CC) $(FLAGS) $(SRC) $(LIBRARY) -o $(NAME)

clean: 
	make clean -C $(LIBFT)
	make clean -C $(FTPRINTF)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(FTPRINTF)
	rm -f $(NAME)

re: fclean all clean