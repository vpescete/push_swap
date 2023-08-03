/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:36:00 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 23:57:33 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exec_case_one(t_stack *stack)
{
	int	i;
	
	if (stack->push.idx_a >= stack->push.idx_b)
	{
		i = -1;
		while (++i < stack->push.idx_b)
			rr(stack, 1);
		i = -1;
		while (++i < stack->push.idx_a - stack->push.idx_b)
			ra(stack, 1);
	}
	else
	{
		i = -1;
		while (++i < stack->push.idx_a)
			rr(stack, 1);
		i = -1;
		while (++i < stack->push.idx_b - stack->push.idx_a)
			rb(stack, 1);
	}
}

void	exec_case_two(t_stack *stack)
{
	int	i;

	if (stack->len_a - stack->push.idx_a >= stack->len_b - stack->push.idx_b)
	{
		i = -1;
		while (++i < stack->len_b - stack->push.idx_b)
			rrr(stack, 1);
		i = -1;
		while (++i < (stack->len_a - stack->push.idx_a)
			- (stack->len_b - stack->push.idx_b))
			rra(stack, 1);
	}
	else
	{
		i = -1;
		while (++i < stack->len_a - stack->push.idx_a)
			rrr(stack, 1);
		i = -1;
		while (++i < (stack->len_b - stack->push.idx_b)
			- (stack->len_a - stack->push.idx_a))
			rrb(stack, 1);
	}
}

void	exec_case_three(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->push.idx_a)
		ra(stack, 1);
	i = -1;
	while (++i < stack->len_b - stack->push.idx_b)
		rrb(stack, 1);
}

void	exec_case_four(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->push.idx_b)
		rb(stack, 1);
	i = -1;
	while (++i < stack->len_a - stack->push.idx_a)
		rra(stack, 1);
}