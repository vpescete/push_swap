/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_move_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:14:18 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/17 00:56:23 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_topush	ft_count_moves(t_stack *stack)
{
	int	i;
	int	index_b;
	int	top_b = 0;
	int tmp_b;
	t_topush	topush;

	topush.index_a = 0;
	topush.index_b = 0;
	topush.count_moves = 0;
	tmp_b = 0;
	i = 0;
	topush.tmp_moves = 0;
	while (i < stack->current_a)
	{
		top_b = ft_next_topb(stack, i);
		tmp_b = ft_find_index_s_b(stack, top_b);
		// printf("top_b: %d -- tmp_b: %d\n", top_b, tmp_b);
		topush = ft_find_max_moves(stack, i, tmp_b, topush);
		// printf("!!!!! count_moves %d\n", topush.count_moves);
		i++;
	}
	// printf(" count_moves: %i\n index_a: %i\n index_b: %i\n", topush.count_moves, topush.index_a, topush.index_b);
	return (topush);
}

int	ft_next_topb(t_stack *stack, int i)
{
	int	j;
	int	tmp;

	j = -1;
	tmp = stack->index_maxb;
	// printf("max di b: %d\nindex_b: %d\n", stack->max_b, stack->index_maxb);
	if (stack->stack_a[i] > stack->max_b || stack->stack_a[i] < stack->min_b)
	{
		return (stack->max_b);
	}
	else
	{
		while (++j < stack->current_b - 1)
		{
			// printf("nb: %i		stack_b[%i]:%d > stack_a[%i]: %d\n		stack_a[%i]: %d > stack_b[%i]: %d\n\n", j, j, stack->stack_b[j], i, stack->stack_a[i], i, stack->stack_a[i], j + 1, stack->stack_b[j + 1]);
			if (stack->stack_a[i] < stack->stack_b[j]
				&& stack->stack_a[i] > stack->stack_b[j + 1])
			{
				tmp = j + 1;
				break;
				// printf("ciao\n");
			}
		}
		return (stack->stack_b[tmp]);
	}
}

int	ft_find_index_s_b(t_stack *stack, int top_b)
{
	int	i;

	i = 0;
	while (i < stack->current_b)
	{
		// printf("   stack->stack_b[%i]: %d -- top_b: %d \n", i, stack->stack_b[i], top_b);
		if (stack->stack_b[i] == top_b)
			break;
		i++;
	}
	return (i);
}

t_topush	ft_find_max_moves(t_stack *stack, int i, int tmp_b, t_topush topush)
{
	int	cur_a;
	int	cur_b;

	cur_a = 0;
	cur_b = 0;
	
	if ((stack->current_a / 2) % 10 != 0)
		cur_a = stack->current_a / 2 + 1;
	else
		cur_a = stack->current_a / 2;
	if ((stack->current_b / 2) % 10 != 0)
		cur_b = stack->current_b / 2 + 1;
	else
		cur_b = stack->current_b / 2;
	if (tmp_b >= cur_b && i >= cur_a)
	{
		if (tmp_b >= i)
			topush.tmp_moves = stack->current_a - i;
		else
			topush.tmp_moves = stack->current_b - tmp_b;
	}
	else if (tmp_b < cur_b && i < cur_a)
	{
		if (tmp_b >= i)
			topush.tmp_moves = tmp_b;
		else
			topush.tmp_moves = i;
	}
	else
	{
		if (tmp_b < cur_b && i >= cur_a)
			topush.tmp_moves = tmp_b + (stack->current_a - i);
		else
			topush.tmp_moves = i + stack->current_b - tmp_b;
	}
	if (topush.count_moves > topush.tmp_moves || i == 0)
	{
		topush.index_a = i;
		topush.index_b = tmp_b;
		topush.count_moves = topush.tmp_moves;
	}
	return (topush);
}
