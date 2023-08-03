/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:14:44 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 19:18:17 by vpescetelli      ###   ########.fr       */
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

typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
	int	index_maxa;
	int	index_mina;
	int	index_maxb;
	int	index_minb;
}			t_stack;

/* swap function */
int		sa(t_stack *stack, int p);
int		sb(t_stack *stack, int p);
int		ss(t_stack *stack, int p);

/* push function */
int		pa(t_stack *stack, int p);
int		pb(t_stack *stack, int p);

/* rotate funciton */
int		ra(t_stack *stack, int p);
int		rb(t_stack *stack, int p);
int		rr(t_stack *stack, int p);

/* reverse rotate funciton */
int		rra(t_stack *stack, int p);
int		rrb(t_stack *stack, int p);
int		rrr(t_stack *stack, int p);

/* error functions*/
void	ft_error(void);

/*utils functions*/
void	free_mtx(char **mtx);
int		check_char(char *s);
void	check_double(t_stack *stack);

/*init functions*/
void	get_input(char **av, int ac, t_stack *stack);
int		count_len_stack(char **mtx);
void	fill_stack(t_stack *stack, char **mtx);
void	init_one(char *string, t_stack *stack);
void	init_two(char **av, int ac, t_stack *stack);

#endif