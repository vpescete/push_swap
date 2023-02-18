/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maxmin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:42:20 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 14:26:31 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_maxmin(t_stack *stack)
{
	int	i;
	
	i = 0;
	while (i < stack->current_b)
	{
		if (stack->stack_b[i] >= stack->max_b)
		{
			stack->max_b = stack->stack_b[i];
			stack->index_maxb = i;
		}
		else if (stack->stack_b[i] < stack->min_b)
		{
			stack->min_b = stack->stack_b[i];
			stack->index_minb = i;
		}
		i++;
	}
}