/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:14:44 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/20 19:34:16 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

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

typedef struct s_curr {
	int	cur_a;
	int	cur_b;
}				t_curr;

typedef struct s_check {
	int	ac;
	int	trigger;
	int	i;
	int	j;
}				t_check;

typedef struct s_topush
{
	int	count_moves;
	int	index_a;
	int	index_b;
	int	tmp_moves;
}				t_topush;

typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	current_a;
	int	current_b;
	int	max_b;
	int	min_b;
	int	*moves;
	int	*tmp_moves;
	int	index_maxa;
	int	index_mina;
	int	index_maxb;
	int	index_minb;
}			t_stack;

/* swap function */
int			sa(t_stack *stack, int p);
int			sb(t_stack *stack, int p);
int			ss(t_stack *stack, int p);

/* push function */
int			pa(t_stack *stack, int p);
int			pb(t_stack *stack, int p);

/* rotate funciton */
int			ra(t_stack *stack, int p);
int			rb(t_stack *stack, int p);
int			rr(t_stack *stack, int p);

/* reverse rotate funciton */
int			rra(t_stack *stack, int p);
int			rrb(t_stack *stack, int p);
int			rrr(t_stack *stack, int p);

/* check and fill stack a */
t_stack		*ft_init(char **av, int ac, t_stack *stack, int k);
t_stack		*ft_check_stack(char *s, t_stack *stack, t_check c);
void		ft_fill_stack(char *s, t_stack *stack, t_check c);
t_stack		*ft_check_av(char **av, t_stack *stack, t_check c);
void		ft_fill_stack_2(char **av, t_stack *stack, t_check c);
void		ft_check_doubles(t_stack *stack);
void		ft_check_init_sort(t_stack *stack);

/* sorting function to push into stack B */
int			ft_sorting(t_stack *stack);
int			ft_first(t_stack *stack);
int			ft_find_index_s_b(t_stack *stack, int top_b);
t_topush	ft_find_max_moves(t_stack *stack, int i, int tmp_b,
				t_topush topush);
int			ft_next_topb(t_stack *stack, int i);
t_topush	ft_count_moves(t_stack *stack);
void		ft_realsort(t_stack	*stack, t_topush topush);
t_topush	ft_new_cheapest(int i, int tmp_b, t_topush topush);
t_topush	ft_index_under(t_stack *stack, int i, int tmp_b, t_topush topush);
t_topush	ft_index_over(t_stack *stack, int i, int tmp_b, t_topush topush);
void		ft_timetopush_under_b(t_stack	*stack, t_topush topush, int i);
void		ft_timetopush_over_b(t_stack	*stack, t_topush topush, int i);
void		ft_timetopush_mix_1(t_stack	*stack, t_topush topush, int i);
void		ft_timetopush_mix_2(t_stack	*stack, t_topush topush, int i);

/* sorting funciton to push into stack A */
void		ft_sorting_a(t_stack *stack);
int			ft_find_next_top_a(t_stack *stack);
void		ft_pushing_to_a(t_stack *stack);
void		final_sorting(t_stack *stack);
t_curr		ft_mid_stacks(t_stack *stack);
void		ft_sta_maj_stb_1(t_stack *stack, int cur_a);
void		ft_sta_maj_stb_2(t_stack *stack, int cur_a, int i_topa, int i);
void		ft_stb_maj_sta_1(t_stack *stack, int cur_a);
void		ft_stb_maj_sta_2(t_stack *stack, int cur_a, int i_topa, int i);

/* checking stacks */
void		ft_check_maxmin(t_stack *stack);
void		ft_find_maxmin_a(t_stack *stack);

void		ft_error_prev(t_stack *stack);
void		ft_error(t_stack *stack);
void		ft_close(t_stack *stack);
void		ft_close_init(t_stack *stack);

#endif