/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushing_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:49:12 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 18:51:19 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_realsort(t_stack	*stack, t_topush topush)
{
	int	cur_a;
	int	cur_b;
	int	i;
	
	cur_a = 0;
	cur_b = 0; 
	i = -1;
	if ((stack->current_a % 2) != 0)
		cur_a = stack->current_a / 2 + 1;
	else
		cur_a = stack->current_a / 2;
	if ((stack->current_b % 2) != 0)
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
	else if (topush.index_a >= cur_a && topush.index_b >= cur_b)
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
	else if (topush.index_a < cur_a && topush.index_b >= cur_b )
	{
		while (++i < topush.index_a)
			ra(stack);
		i = -1;
		while (++i < stack->current_b - topush.index_b)
			rrb(stack);
	}
	else if (topush.index_a >= cur_a && topush.index_b < cur_b )
	{
		while (++i < topush.index_b)
			rb(stack);
		i = -1;
		while (++i < stack->current_a - topush.index_a)
			rra(stack);
	}
	pb(stack);
}
