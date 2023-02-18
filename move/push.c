/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:08:54 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 18:48:32 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack *stack)
{
	printf("pa\n");
	int	i;
	int	j;
	
	j = 0;
	i = stack->current_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->current_a++;
	stack->stack_a[0] = stack->stack_b[0];
	i = 1;
	while (i < stack->current_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->current_b--;
	return (push_a);
}

int	pb(t_stack *stack)
{
	printf("pb\n");
	int	i;
	int	j;
	
	j = 0;
	i = stack->current_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->current_b++;
	stack->stack_b[0] = stack->stack_a[0];
	i = 1;
	while (i < stack->current_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->current_a--;
	ft_check_maxmin(stack);
	return (push_b);
}