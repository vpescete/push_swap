/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:58:11 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/04 00:05:55 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index_b(t_stack *stack, int idx_a)
{
	int	i;

	i = -1;
	stack->tmp.idx_a = idx_a;
	stack->tmp.idx_b = 0;
	if (stack->stack_a[idx_a] > stack->stack_b[stack->index_maxb]
		|| stack->stack_a[idx_a] < stack->stack_b[stack->index_minb])
	{
		stack->tmp.idx_b = stack->index_maxb;
		return ;
	}
	while (++i < stack->len_b - 1)
	{
		if (stack->stack_a[idx_a] < stack->stack_b[i]
			&& stack->stack_a[idx_a] > stack->stack_b[i + 1])
		{
			stack->tmp.idx_b = i + 1;
			return ;
		}
	}
}

void	save_mv(t_stack *stack)
{
	stack->push.idx_a = stack->tmp.idx_a;
	stack->push.idx_b = stack->tmp.idx_b;
	stack->push.mv = stack->tmp.tmp_mv;
}

void	find_cheapest_mv(t_stack *stack)
{
	int	half_a;
	int	half_b;
	
	if (stack->len_a % 2 != 0)
		half_a = stack->len_a / 2 + 1;
	else
		half_a = stack->len_a / 2;
	if (stack->len_b % 2 != 0)
		half_b = stack->len_b / 2 + 1;
	else
		half_b = stack->len_b / 2;
	if (stack->tmp.idx_a < half_a && stack->tmp.idx_b < half_b)
		case_one(stack);
	else if (stack->tmp.idx_a >= half_a && stack->tmp.idx_b >= half_b)
		case_two(stack);
	else if (stack->tmp.idx_a < half_a && stack->tmp.idx_b >= half_b)
		stack->tmp.tmp_mv = stack->tmp.idx_a
			+ (stack->len_b - stack->tmp.idx_b);
	else if (stack->tmp.idx_a >= half_a && stack->tmp.idx_b < half_b)
		stack->tmp.tmp_mv = stack->tmp.idx_b
			+ (stack->len_a - stack->tmp.idx_a);
	// printf("CASES -> IDX_A: %d\n", stack->tmp.idx_a);
	if (stack->tmp.idx_a == 0 || stack->tmp.tmp_mv < stack->push.mv)
		save_mv(stack);
}

void	cheapest_num(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len_a)
	{
		find_index_b(stack, i);
		find_cheapest_mv(stack);
	}
}

void	execute_move(t_stack *stack)
{
	int	half_a;
	int	half_b;
	
	if (stack->len_a % 2 != 0)
		half_a = stack->len_a / 2 + 1;
	else
		half_a = stack->len_a / 2;
	if (stack->len_b % 2 != 0)
		half_b = stack->len_b / 2 + 1;
	else
		half_b = stack->len_b / 2;
	if (stack->push.idx_a < half_a && stack->push.idx_b < half_b)
		exec_case_one(stack);
	else if (stack->push.idx_a >= half_a && stack->push.idx_b >= half_b)
		exec_case_two(stack);
	else if (stack->push.idx_a < half_a && stack->push.idx_b >= half_b)
		exec_case_three(stack);
	else if (stack->push.idx_a >= half_a && stack->push.idx_b < half_b)
		exec_case_four(stack);
	pb(stack, 1);
}

void	sort(t_stack *stack)
{
	pb(stack, 1);
	pb(stack, 1);
	while (stack->len_a > 3)
	{
		cheapest_num(stack);
		execute_move(stack);
	}
	three_sort(stack);
	// must finish to push all the stack b into stack a
	// while (stack->len_b != 0)
	// {
	// 	best_move(stack);
	// 	final_push(stack);
	// }
}

void	three_sort(t_stack *stack)
{
	set_maxmin(stack);
	if (stack->index_maxa == 1 && stack->index_mina == 0)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (stack->index_maxa == 0 && stack->index_mina == 1)
		ra(stack, 1);
	else if (stack->index_maxa == 0 && stack->index_mina == 2)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (stack->index_maxa == 1 && stack->index_mina == 2)
		rra(stack, 1);
	else if (stack->index_maxa == 2 && stack->index_mina == 1)
		sa(stack, 1);
}

void	init_param(t_stack *stack)
{
	stack->tmp.idx_a = 0;
	stack->tmp.idx_b = 0;
	stack->tmp.tmp_mv = 0;
}

void	sorting(t_stack *stack)
{
	check_sorted(stack);
	init_param(stack);
	if (stack->len_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			sa(stack, 1);
		ft_close(stack);
	}
	else if (stack->len_a == 3)
		three_sort(stack);
	else
		sort(stack);
}

int	main(int ac, char **av)
{
	t_stack		stack;

	if (ac > 1)
		get_input(av, ac, &stack);
	sorting(&stack);
	return (0);
}
