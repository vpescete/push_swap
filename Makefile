NAME = push_swap

SRC = move/push.c move/reverse.c move/rotate.c move/swap.c \
		check_input/ft_check_input.c \
		sorting/ft_sorting.c sorting/ft_count_move_to_b.c sorting/ft_check_maxmin.c sorting/ft_pushing_to_b.c sorting/ft_sorting_a.c\
		push_swap.c ft_close.c

OBJ = $(SRC.c=.o)

CC = gcc
FLAG = -Wall -Werror -Wextra

LIBFT := libft/
LIBRARY := libft/libft.a

all : 
		make -C $(LIBFT)
	$(CC) $(FLAGS) $(SRC) $(LIBRARY) -o $(NAME) -g

clean: 
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all clean