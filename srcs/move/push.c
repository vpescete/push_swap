/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:08:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 19:23:01 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack *stack, int p)
{
	int	i;

	i = stack->len_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->len_a++;
	stack->stack_a[0] = stack->stack_b[0];
	i = 1;
	while (i < stack->len_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->len_b--;
	if (p == 1)
		ft_printf("pa\n");
}

void	pb(t_stack *stack, int p)
{
	int	i;

	i = stack->len_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->len_b++;
	stack->stack_b[0] = stack->stack_a[0];
	i = 1;
	while (i < stack->len_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->len_a--;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("pb\n");
}
