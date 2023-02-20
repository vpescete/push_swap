/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:18 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/20 18:00:38 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sorting(t_stack *stack)
{
	int	len;

	if (stack->current_a == 3)
	{
		ft_sorting_a(stack);
		ft_close(stack);
	}
	len = 0;
	len += ft_first(stack);
	return (len);
}

int	ft_first(t_stack *stack)
{
	stack->current_b = 0;
	stack->min_b = 0;
	stack->max_b = 0;
	if (stack->stack_a[0] > stack->stack_a[1])
	{
		stack->min_b = stack->stack_a[1];
		stack->max_b = stack->stack_a[0];
	}
	else
	{
		stack->min_b = stack->stack_a[0];
		stack->max_b = stack->stack_a[1];
	}
	pb(stack, 1);
	pb(stack, 1);
	return (2);
}
