/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:14:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 19:24:22 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack *stack, int p)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, int p)
{
	int	tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("sb\n");
}

void	ss(t_stack *stack, int p)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	ft_check_maxmin(stack);
	if (p == 1)
		ft_printf("ss\n");
}
