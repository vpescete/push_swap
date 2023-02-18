/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 18:11:24 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stack *stack)
{
	printf("rra\n");
	int i;
	int tmp;

	tmp = stack->stack_a[stack->current_a - 1];
	i = stack->current_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;		
	}
	stack->stack_a[0] = tmp;
	ft_check_maxmin(stack);
	return (reverse_a);
}

int	rrb(t_stack *stack)
{
	printf("rrb\n");
	int i;
	int tmp;

	tmp = stack->stack_b[stack->current_b - 1];
	i = stack->current_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	ft_check_maxmin(stack);
	return (reverse_b);
}

int rrr(t_stack *stack)
{
	printf("rrr\n");
	int i;
	int tmp;

	tmp = stack->stack_a[stack->current_a - 1];
	i = stack->current_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;		
	}
	stack->stack_a[0] = tmp;
	tmp = stack->stack_b[stack->current_b - 1];
	i = stack->current_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	ft_check_maxmin(stack);
	return (reverse_ab);
}
