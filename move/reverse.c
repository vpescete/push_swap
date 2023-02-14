/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/13 16:06:25 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stack *stack)
{
	int i;
	int tmp;

	tmp = stack->stack_a[stack->current_a];
	i = stack->current_a - 1;
	while (i > 0)
	{
		stack->stack_a[i + 1] = stack->stack_a[i];
		i--;		
	}
	stack->stack_a[0] = tmp;
	return (reverse_a);
}

int	rrb(t_stack *stack)
{
	int i;
	int tmp;

	tmp = stack->stack_b[stack->current_b];
	i = stack->current_b - 1;
	while (i > 0)
	{
		stack->stack_b[i + 1] = stack->stack_b[i];
		i--;
	}
	stack->stack_b[0] = tmp;
	return (reverse_b);
}

int rrr(t_stack *stack)
{
	int i;
	int tmp;

	tmp = stack->stack_a[stack->current_a];
	i = stack->current_a - 1;
	while (i > 0)
	{
		stack->stack_a[i + 1] = stack->stack_a[i];
		i--;
	}
	stack->stack_a[0] = tmp;
	tmp = stack->stack_b[stack->current_b];
	i = stack->current_b - 1;
	while (i > 0)
	{
		stack->stack_b[i + 1] = stack->stack_b[i];
		i--;
	}
	stack->stack_b[0] = tmp;
	return (reverse_ab);
}
