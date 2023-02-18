/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:13:49 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 18:51:28 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sorting_a(t_stack *stack)
{
	ft_find_maxmin_a(stack);
	if (stack->index_mina == 0)
	{
		if (stack->index_maxa == 1)
		{
			rra(stack);
			sa(stack);
		}
	}
	else if (stack->index_mina == 1)
	{
		if (stack->index_maxa == 0)
			ra(stack);
		else
			sa(stack);
	}
	else
	{
		if (stack->index_maxa == 0)
			sa(stack);
		rra(stack);
	}
}

void	ft_find_maxmin_a(t_stack *stack)
{
	int	i;

	i = 0;
	stack->index_mina = i;
	while (++i < stack->current_a)
	{
		if (stack->stack_a[i] < stack->stack_a[stack->index_mina])
			stack->index_mina = i;
	}
	i = 0;
	stack->index_maxa = i;
	while (++i < stack->current_a)
	{
		if (stack->stack_a[i] > stack->stack_a[stack->index_maxa])
			stack->index_maxa = i;
	}
}

void	ft_pushing_to_a(t_stack *stack)
{
	int	cur_a;
	int	cur_b;
	int	i_topa;
	int	i;
	

	cur_a = 0;
	cur_b = 0;
	i_topa = 0; 
	i = -1;
	if ((stack->current_a % 2) != 0)
		cur_a = stack->current_a / 2 + 1;
	else
		cur_a = stack->current_a / 2;
	ft_find_maxmin_a(stack);
	if (stack->stack_b[0] < stack->stack_a[0])
	{
		if (stack->stack_b[0] < stack->stack_a[stack->index_mina])
		{
			if (stack->index_mina < cur_a)
			{
				while (stack->index_mina != 0)
				{
					ra(stack);
					ft_find_maxmin_a(stack);
				}
			}
			else 
			{
				while (stack->index_mina != 0)
				{
					rra(stack);
					ft_find_maxmin_a(stack);
				}
			}
		}
		else
		{
			i_topa = ft_find_next_top_A(stack);
			if (i_topa >= cur_a)
			{
				while (stack->current_a - i_topa > ++i)
					rra(stack);
			}
			else
			{
				while (i_topa > ++i)
					ra(stack);
			}
		}
	}
	if (stack->stack_b[0] > stack->stack_a[0])
	{
		if (stack->stack_b[0] > stack->stack_a[stack->index_maxa])
		{
			if (stack->index_maxa == stack->current_a - 1)
			{
				pa(stack);
				return ;
			}
			else if (stack->index_maxa >= cur_a)
			{
				while (stack->current_a - stack->index_maxa - 1 != 0)
				{
					rra(stack);
					ft_find_maxmin_a(stack);
				}
			}
			else
			{
				while (stack->index_maxa != stack->current_a - 1)
				{
					ra(stack);
					ft_find_maxmin_a(stack);
				}
			}
		}
		else if (stack->stack_b[0] < stack->stack_a[stack->index_maxa])
		{
			i_topa = ft_find_next_top_A(stack);
			if (i_topa >= cur_a)
			{
				while (++i < stack->current_a - i_topa)
				{
					rra(stack);
					ft_find_maxmin_a(stack);
				}
			}
			else
			{
				while (++i < i_topa)
				{
					ra(stack);
					ft_find_maxmin_a(stack);
				}
			}
		}
	}
	pa(stack);
}

int	ft_find_next_top_A(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->current_a - 1)
	{
		if (stack->stack_b[0] > stack->stack_a[i]
			&& stack->stack_b[0] < stack->stack_a[i + 1])
			return(i + 1);
		i++;
	}
	return (0);
}

void	final_sorting(t_stack *stack)
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
	ft_find_maxmin_a(stack);
	if (stack->index_mina >= cur_a)
	{
		while (++i < stack->current_a - stack->index_mina)
			rra(stack);
	}
	else
	{
		while (++i < stack->index_mina)
			ra(stack);
	}
}
