/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:14:44 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/04 17:16:26 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_push {
	int	idx_a;
	int	idx_b;
	int	mv;
}	t_push;

typedef struct s_temp {
	int	idx_a;
	int	idx_b;
	int	tmp_mv;
}	t_temp;

typedef struct s_stack {
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;
	int		index_maxa;
	int		index_mina;
	int		index_maxb;
	int		index_minb;
	t_temp	tmp;
	t_push	push;
}			t_stack;

/* swap function */
void	sa(t_stack *stack, int p);
void	sb(t_stack *stack, int p);
void	ss(t_stack *stack, int p);

/* push function */
void	pa(t_stack *stack, int p);
void	pb(t_stack *stack, int p);

/* rotate funciton */
void	ra(t_stack *stack, int p);
void	rb(t_stack *stack, int p);
void	rr(t_stack *stack, int p);

/* reverse rotate funciton */
void	rra(t_stack *stack, int p);
void	rrb(t_stack *stack, int p);
void	rrr(t_stack *stack, int p);

/* error functions*/
void	ft_error(void);

/*utils functions*/
void	free_mtx(char **mtx);
int		check_char(char *s);
void	check_double(t_stack *stack);
void	ft_close(t_stack *stack);
void	set_maxmin(t_stack *stack);
void	check_sorted(t_stack *stack);
void	set_maxmin_b(t_stack *stack);
void	set_maxmin_a(t_stack *stack);

/*init functions*/
void	get_input(char **av, int ac, t_stack *stack);
int		count_len_stack(char **mtx);
void	fill_stack(t_stack *stack, char **mtx);
void	init_one(char *string, t_stack *stack);
void	init_two(char **av, int ac, t_stack *stack);

/*sort functions*/
void	case_one(t_stack *stack);
void	case_two(t_stack *stack);
void	exec_case_one(t_stack *stack);
void	exec_case_two(t_stack *stack);
void	exec_case_three(t_stack *stack);
void	exec_case_four(t_stack *stack);
void	three_sort(t_stack *stack);

#endif