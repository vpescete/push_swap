/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:35:43 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/13 16:20:11 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stack *stack)
{
	int i;
	int tmp;

	tmp = stack->stack_a[0];
	i = 1;
	while (i < stack->current_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i] = tmp;
	return (rotate_a);
}

int	rb(t_stack *stack)
{
	int i;
	int tmp;

	tmp = stack->stack_b[0];
	i = 1;
	while (i < stack->current_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i] = tmp;
	return (rotate_b);
}

int rr(t_stack *stack)
{
	int i;
	int tmp;

	tmp = stack->stack_a[0];
	i = 1;
	while (i < stack->current_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i] = tmp;
	tmp = stack->stack_b[0];
	i = 1;
	while (i < stack->current_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i] = tmp;
	return (rotate_ab);
}
