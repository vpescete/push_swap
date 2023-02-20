/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pusha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:31:28 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/20 19:42:58 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_curr	ft_mid_stacks(t_stack *stack)
{
	t_curr	c;

	if ((stack->current_a % 2) != 0)
		c.cur_a = stack->current_a / 2 + 1;
	else
		c.cur_a = stack->current_a / 2;
	return (c);
}

void	ft_sta_maj_stb_1(t_stack *stack, int cur_a)
{
	if (stack->index_mina < cur_a)
	{
		while (stack->index_mina != 0)
		{
			ra(stack, 1);
			ft_find_maxmin_a(stack);
		}
	}
	else
	{
		while (stack->index_mina != 0)
		{
			rra(stack, 1);
			ft_find_maxmin_a(stack);
		}
	}
}

void	ft_sta_maj_stb_2(t_stack *stack, int cur_a, int i_topa, int i)
{
	i_topa = ft_find_next_top_a(stack);
	if (i_topa >= cur_a)
	{
		while (stack->current_a - i_topa > ++i)
			rra(stack, 1);
	}
	else
	{
		while (i_topa > ++i)
			ra(stack, 1);
	}
}

void	ft_stb_maj_sta_1(t_stack *stack, int cur_a)
{
	if (stack->index_maxa == stack->current_a - 1)
		return ;
	else if (stack->index_maxa >= cur_a)
	{
		while (stack->current_a - stack->index_maxa - 1 != 0)
		{
			rra(stack, 1);
			ft_find_maxmin_a(stack);
		}
	}
	else
	{
		while (stack->index_maxa != stack->current_a - 1)
		{
			ra(stack, 1);
			ft_find_maxmin_a(stack);
		}
	}
}

void	ft_stb_maj_sta_2(t_stack *stack, int cur_a, int i_topa, int i)
{
	i_topa = ft_find_next_top_a(stack);
	if (i_topa >= cur_a)
	{
		while (++i < stack->current_a - i_topa)
		{
			rra(stack, 1);
			ft_find_maxmin_a(stack);
		}
	}
	else
	{
		while (++i < i_topa)
		{
			ra(stack, 1);
			ft_find_maxmin_a(stack);
		}
	}
}
