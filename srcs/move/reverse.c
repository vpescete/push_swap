/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:15 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 19:39:37 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[stack->len_a - 1];
	i = stack->len_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	if (p == 1)
		ft_printf("rra\n");
	set_maxmin(stack);
}

void	rrb(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_b[stack->len_b - 1];
	i = stack->len_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (p == 1)
		ft_printf("rrb\n");
	set_maxmin(stack);
	
}

void	rrr(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[stack->len_a - 1];
	i = stack->len_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	tmp = stack->stack_b[stack->len_b - 1];
	i = stack->len_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (p == 1)
		ft_printf("rrr\n");
	set_maxmin(stack);
}
