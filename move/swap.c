/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:14:21 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 18:12:33 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack *stack)
{
	printf("sa\n");
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	ft_check_maxmin(stack);
	return (swap_a);
}

int	sb(t_stack *stack)
{
	printf("sb\n");
	int	tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	ft_check_maxmin(stack);
	return (swap_b);
}

int ss(t_stack *stack)
{
	printf("ss\n");
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	ft_check_maxmin(stack);
	return (swap_ab);
}