/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:14:44 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/14 19:29:39 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

enum e_MOVES {
	swap_a = 0,
	swap_b,
	swap_ab,
	push_a,
	push_b,
	rotate_a,
	rotate_b,
	rotate_ab,
	reverse_a,
	reverse_b,
	reverse_ab,
};

typedef struct s_topush
{
	int	count_moves;
	int	index_a;
	int	index_b;
	int tmp_moves;
}				t_topush;


typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	current_a;
	int	current_b;
	int	max_b;
	int	min_b;
	int	*moves;
	int *tmp_moves;
}				t_stack;

/* swap function */
int 		sa(t_stack *stack);
int 		sb(t_stack *stack);
int 		ss(t_stack *stack);

/* push function */
int			pa(t_stack *stack);
int			pb(t_stack *stack);

/* rotate funciton */
int			ra(t_stack *stack);
int			rb(t_stack *stack);
int			rr(t_stack *stack);

/* reverse rotate funciton */
int			rra(t_stack *stack);
int			rrb(t_stack *stack);
int			rrr(t_stack *stack);

/* check and fill stack a */
t_stack		*ft_check_stack(char *input, t_stack *stack);
void		ft_fill_stack(char *s, t_stack *stack);
t_stack		*ft_check_av(char **av, int ac, t_stack *stack);
void		ft_fill_stack_2(char **av, int ac, t_stack *stack);
void		ft_check_doubles(t_stack *stack);

/* sorting function */
int			ft_sorting(t_stack *stack);
int			ft_first(t_stack *stack);
int			ft_find_index_s_b(t_stack *stack, int top_b);
void		ft_find_max_moves(t_stack *stack, int i, int tmp_b,
				t_topush topush);
int			ft_next_topb(t_stack *stack, int i);
t_topush	ft_count_moves(t_stack *stack);

/* checking stacks */
void		ft_check_maxmin(t_stack *stack);


void		ft_close(t_stack *stack);

#endif