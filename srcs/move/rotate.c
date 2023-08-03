/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:35:43 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 19:21:06 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->current_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("ra\n");
	return (rotate_a);
}

int	rb(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->current_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("rb\n");
	return (rotate_b);
}

int	rr(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->current_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->current_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("rr\n");
	return (rotate_ab);
}
