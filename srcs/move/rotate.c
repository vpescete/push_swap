/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:35:43 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/04 17:17:33 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	if (p == 1)
		ft_printf("ra\n");
	set_maxmin_a(stack);
}

void	rb(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	if (p == 1)
		ft_printf("rb\n");
	set_maxmin_b(stack);
}

void	rr(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	if (p == 1)
		ft_printf("rr\n");
	set_maxmin(stack);
}
