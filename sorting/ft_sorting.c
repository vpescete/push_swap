/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:18 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/17 00:57:59 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sorting(t_stack *stack)
{
	int	len;

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
	pb(stack);
	pb(stack);
	return (2);
}

void	ft_realsort(t_stack	*stack, t_topush topush)
{
	int	cur_a;
	int	cur_b;
	int	i;
	

	/* cur_a e cur_b sono le meta' degli stack, nel caso il numero di elementi nello stack sia negativo, allora mettiamo un + 1 */ 	
	cur_a = 0;
	cur_b = 0;
	i = -1;
	if ((stack->current_a / 2) % 10 != 0)
		cur_a = stack->current_a / 2 + 1;
	else
		cur_a = stack->current_a / 2;
	if ((stack->current_b / 2) % 10 != 0)
		cur_b = stack->current_b / 2 + 1;
	else
		cur_b = stack->current_b / 2;
	if (topush.index_a < cur_a && topush.index_b < cur_b)
	{
		if (topush.index_a == topush.index_b)
		{
			while (++i < topush.index_a)
				rr(stack);
		}
		else if (topush.index_a > topush.index_b)
		{
			while (++i < topush.index_b)
				rr(stack);
			i = -1;
			while (++i < (topush.index_a - topush.index_b))
				ra(stack);
		}
		else
		{
			while (++i < topush.index_a)
				rr(stack);
			i = -1;
			while (++i < (topush.index_b - topush.index_a))
				rb(stack);
		}
	}
	else if (topush.index_a > cur_a && topush.index_b > cur_b)
	{
		if ((stack->current_a - topush.index_a) >= (stack->current_b - topush.index_b))
		{
			while (++i < (stack->current_b - topush.index_b))
				rrr(stack);
			i = -1;
			while (++i < (stack->current_a - topush.index_a) - (stack->current_b - topush.index_b))
				rra(stack);
		}
		else if ((stack->current_a - topush.index_a) < (stack->current_b - topush.index_b))
		{
			while (++i < (stack->current_a - topush.index_a))
				rrr(stack);
			i = -1;
			while (++i < (stack->current_b - topush.index_b) - (stack->current_a - topush.index_a))
				rrb(stack);
		}		
	}
	else if (topush.index_a < cur_a && topush.index_b > cur_b )
	{
		while (++i < topush.index_a)
			ra(stack);
		i = -1;
		while (++i < stack->current_b - topush.index_b)
			rrb(stack);
	}
	else if (topush.index_a > cur_a && topush.index_b < cur_b )
	{
		while (++i < topush.index_b)
			rb(stack);
		i = -1;
		while (++i < stack->current_a - topush.index_a)
			rra(stack);
	}
	pb(stack);
}
