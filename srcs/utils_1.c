/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:30:14 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/03 20:33:20 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_maxmin_a(t_stack *stack)
{
	int	i;

	i = -1;
	stack->index_maxa = 0;
	while (++i < stack->len_a)
	{
		if (stack->stack_a[i] > stack->stack_a[stack->index_maxa])
			stack->index_maxa = i;
	}
	i = -1;
	stack->index_mina = 0;
	while (++i < stack->len_a)
	{
		if (stack->stack_a[i] < stack->stack_a[stack->index_mina])
			stack->index_mina = i;
	}
}

void	set_maxmin_b(t_stack *stack)
{
	int	i;

	i = -1;
	stack->index_maxb = 0;
	while (++i < stack->len_b)
	{
		if (stack->stack_b[i] > stack->stack_b[stack->index_maxb])
			stack->index_maxb = i;
	}
	i = -1;
	stack->index_minb = 0;
	while (++i < stack->len_b)
	{
		if (stack->stack_b[i] < stack->stack_b[stack->index_minb])
			stack->index_minb = i;
	}
}

void	set_maxmin(t_stack *stack)
{
	set_maxmin_a(stack);
	set_maxmin_b(stack);
}

void	check_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len_a)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			break ;
	}
	if (i != stack->len_a - 1)
		return ;
	ft_close(stack);
}
